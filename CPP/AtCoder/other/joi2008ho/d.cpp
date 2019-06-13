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

typedef tuple<int, int, int> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto row = initVec2<tup>(n + 2, 0);
    int num = 0;
    row[0].emplace_back(num++, 0, 0);
    rep(i, n){
        int k;
        cin >> k;
        rep(j, k){
            int x, d;
            cin >> x >> d;
            row[i+1].emplace_back(num++, x, d);
        }
    }
    row[n+1].emplace_back(num++, 0, 0);

    auto dp = initVec2<int>(num, m + 1, INF);
    dp[0][0] = 0;
    rep(i, n + 1){
        for(tup t1 : row[i]){
            int v, x1, d1;
            tie(v, x1, d1) = t1;
            for(tup t2 : row[i+1]){
                int u, x2, d2;
                tie(u, x2, d2) = t2;

                int dist = (d1 + d2) * abs(x1 - x2);
                if(v == 0 || u == num - 1){
                    dist = 0;
                }
                rep(j, m + 1){
                    dp[u][j] = min(dp[u][j], dp[v][j] + dist);
                }
            }
            if(i + 2 > n + 1){
                continue;
            }
            for(tup t2 : row[i+2]){
                int u, x2, d2;
                tie(u, x2, d2) = t2;

                int dist = (d1 + d2) * abs(x1 - x2);
                if(v == 0 || u == num - 1){
                    dist = 0;
                }
                rep(j, m){
                    dp[u][j+1] = min(dp[u][j+1], dp[v][j] + dist);
                }
            }
        }
    }

    int ans = INF;
    rep(i, m + 1){
        ans = min(ans, dp[num-1][i]);
    }
    cout << ans << endl;

    return 0;
}
