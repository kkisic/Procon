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

int n;
vector<vector<int>> edge;

P dfs(int v, int par){
    P ans = {1, 1};

    for(int u : edge[v]){
        if(u == par){
            continue;
        }

        P tmp = dfs(u, v);
        ans.first *= (tmp.first + tmp.second) % MOD;
        ans.first %= MOD;
        ans.second *= tmp.first;
        ans.second %= MOD;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    edge = vector<vector<int>>(n, vector<int>());
    rep(i, n - 1){
        int x, y;
        cin >> x >> y;
        edge[x-1].push_back(y-1);
        edge[y-1].push_back(x-1);
    }

    P ans = dfs(0, -1);
    cout << (ans.first + ans.second) % MOD << endl;

    return 0;
}
