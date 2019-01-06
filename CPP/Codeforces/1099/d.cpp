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

vector<vector<int>> edge;
vector<int> s, h, a;
int n;

void dfs(int v, int par){
    h[v] = h[par] + 1;
    if(s[v] == -1 && h[v] % 2 != 0){
        cout << -1 << endl;
        exit(0);
    }

    if(s[v] != -1){
        if(s[v] < s[par]){
            cout << -1 << endl;
            exit(0);
        }
        a[v] = s[v] - s[par];
    }else{
        int need = INF;
        for(int u : edge[v]){
            if(s[u] == -1){
                continue;
            }
            need = min(need, s[u]);
        }
        if(need < s[par]){
            cout << -1 << endl;
            exit(0);
        }
        if(need != INF){
            a[v] = need - s[par];
            s[v] = need;
        }else{
            s[v] = s[par];
        }
    }

    for(int u : edge[v]){
        dfs(u, v);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    edge = vector<vector<int>>(n+1, vector<int>());
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        edge[p].push_back(i);
    }

    s = vector<int>(n+1);
    rep(i, n) cin >> s[i+1];
    h = vector<int>(n+1);
    a = vector<int>(n+1, 0);

    dfs(1, 0);
    int ans = 0;
    rep(i, n){
        ans += a[i+1];
    }
    cout << ans << endl;

    return 0;
}
