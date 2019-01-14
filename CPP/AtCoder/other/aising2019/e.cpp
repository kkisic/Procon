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
vector<int> a, child;
vector<vector<int>> edge;
int dp[5001][5001][2];
int sub[5001][2];

void dfs(int v, int par){
    if(a[v] > 0){
        dp[v][0][0] = a[v];
    }else{
        dp[v][0][1] = a[v];
    }

    child[v] = 1;

    for(int u : edge[v]){
        if(u == par){
            continue;
        }
        dfs(u, v);
        for(int i = 0; i < child[v]; i++){
            for(int j = 0; j < child[u]; j++){
                rep(k1, 2) rep(k2, 2){
                    sub[i+j][k1|k2] = min(sub[i+j][k1|k2], dp[v][i][k1] + dp[u][j][k2]);
                    if(k2 == 0 && dp[u][j][k2] < INF || dp[u][j][k2] < 0){
                        sub[i+j+1][k1] = min(sub[i+j+1][k1], dp[v][i][k1]);
                    }
                }

            }
        }
        child[v] += child[u];
        for(int i = 0; i < child[v]; i++){
            rep(k, 2){
                dp[v][i][k] = sub[i][k];
                sub[i][k] = INF;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a = vector<int>(n + 1);
    rep(i, n) cin >> a[i+1];

    edge = vector<vector<int>>(n + 1, vector<int>());
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    rep(i, n+1) rep(j, n+1) rep(k, 2) dp[i][j][k] = INF;
    rep(i, n+1) rep(k, 2) sub[i][k] = INF;

    child = vector<int>(n + 1);
    dfs(1, 0);

    int ans = INF;
    rep(i, n + 1){
        if(dp[1][i][0] != INF){
            ans = min(ans, i);
        }
        if(dp[1][i][1] < 0){
            ans = min(ans, i);
        }
    }
    cout << ans << endl;

    return 0;
}
