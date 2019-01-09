#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n, m;
vector<int> sub, ans;
vector<vector<int>> edge;

void dfs1(int v, int par){
    for(int u : edge[v]){
        if(u == par){
            continue;
        }
        dfs1(u, v);
        sub[v] *= (sub[u] + 1) % m;
        sub[v] %= m;
    }
}

void dfs2(int v, int par, int parSub){
    vector<int> left(SZ(edge[v]) + 1, 1), right(SZ(edge[v]) + 1, 1);
    rep(i, SZ(edge[v])){
        if(edge[v][i] == par){
            left[i+1] = left[i];
            continue;
        }
        left[i+1] = left[i] * ((sub[edge[v][i]] + 1) % m);
        left[i+1] %= m;
    }
    for(int i = SZ(edge[v]); i > 0; i--){
        if(edge[v][i-1] == par){
            right[i-1] = right[i];
            continue;
        }
        right[i-1] = right[i] * ((sub[edge[v][i-1]] + 1) % m);
        right[i-1] %= m;
    }

    rep(i, SZ(edge[v])){
        if(edge[v][i] == par){
            continue;
        }
        int tmp = (parSub + 1) % m;
        tmp *= left[i];
        tmp %= m;
        tmp *= right[i+1];
        tmp %= m;
        ans[edge[v][i]] = sub[edge[v][i]] * ((tmp + 1) % m) % m;

        dfs2(edge[v][i], v, tmp);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    edge = vector<vector<int>>(n + 1, vector<int>());
    rep(i, n - 1){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    sub = vector<int>(n + 1, 1);
    ans = vector<int>(n + 1);

    dfs1(1, 0);
    dfs2(1, 0, 0);
    ans[1] = sub[1];
    rep(i, n){
        cout << ans[i+1] << endl;
    }

    return 0;
}
