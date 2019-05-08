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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int n;
vector<int> child, sub;
vector<vector<P>> edge;
vector<vector<int>> dp;

void dfs(int v, int p, int h){
    dp[v][0] = 0;
    child[v] = 1;

    for(P pp : edge[v]){
        int u = pp.first;
        int l = pp.second;
        if(u == p){
            continue;
        }
        dfs(u, v, l);

        rep(i, child[v]){
            rep(j, child[u] + 1){
                if(dp[v][i] + dp[u][j] > h){
                    continue;
                }
                sub[i+j] = min(sub[i+j], dp[v][i] + dp[u][j]);
            }
        }

        child[v] += child[u];
        rep(i, child[v]){
            if(sub[i] == INF){
                continue;
            }
            dp[v][i] = sub[i];
            sub[i] = INF;
        }
    }

    for(int i = child[v] - 1; i >= 0; i--){
        if(dp[v][i] != INF){
            dp[v][i+1] = h;
            break;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    child = vector<int>(n);
    sub = vector<int>(n, INF);
    edge = initVec2<P>(n, 0);
    dp = initVec2<int>(n, n + 1, INF);
    for(int i = 1; i <= n - 1; i++){
        int p, h;
        cin >> p >> h;
        edge[i].emplace_back(p, h);
        edge[p].emplace_back(i, h);
    }

    dfs(0, -1, INF);
    int ans = 0;
    rep(i, n){
        if(dp[0][i] != INF){
            ans = max(ans, i);
        }
    }
    cout << ans + 1 << endl;

    return 0;
}
