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
const int MOD = 100000;

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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    cin >> w >> h;
    auto dp = initVec3<vector<int>>(w, h, 2, vector<int>(2));
    dp[0][0][0][1] = dp[0][0][1][0] = 1;
    rep(i, w){
        rep(j, h){
            if(i + 1 < w){
                (dp[i+1][j][0][0] += dp[i][j][0][0]) %= MOD;
                (dp[i+1][j][0][0] += dp[i][j][0][1]) %= MOD;
                (dp[i+1][j][0][1] += dp[i][j][1][1]) %= MOD;
            }
            if(j + 1 < h){
                (dp[i][j+1][1][0] += dp[i][j][0][0]) %= MOD;
                (dp[i][j+1][1][1] += dp[i][j][1][0]) %= MOD;
                (dp[i][j+1][1][1] += dp[i][j][1][1]) %= MOD;
            }
        }
    }

    int ans = 0;
    rep(i, 2){
        rep(j, 2){
            (ans += dp[w-1][h-1][i][j]) %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
