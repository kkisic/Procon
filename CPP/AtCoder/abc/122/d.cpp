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

int dp[4][4][4][100] = {};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    rep(i, 4) rep(j, 4) rep(k, 4){
        if(i == 0 && j == 2 && k == 1){
            continue;
        }
        if(i == 0 && j == 1 && k == 2){
            continue;
        }
        if(i == 2 && j == 0 && k == 1){
            continue;
        }
        dp[i][j][k][0] = 1;
    }
    rep(i, n - 3){
        rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4){
            if(k == 0 && l == 2 && m == 1){
                continue;
            }
            if(k == 0 && l == 1 && m == 2){
                continue;
            }
            if(k == 2 && l == 0 && m == 1){
                continue;
            }
            if(j == 0 && l == 2 && m == 1){
                continue;
            }
            if(j == 0 && k == 2 && m == 1){
                continue;
            }
            dp[k][l][m][i+1] += dp[j][k][l][i];
            dp[k][l][m][i+1] %= MOD;
        }
    }

    int ans = 0;
    rep(i, 4) rep(j, 4) rep(k, 4){
        ans += dp[i][j][k][n-3];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
