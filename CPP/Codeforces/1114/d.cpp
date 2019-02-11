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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e9;
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

//dp[l][r][isRight]
int dp[5000][5000][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    rep(i, n) rep(j, n) rep(k, 2) dp[i][j][k] = INF;

    rep(i, n) rep(j, 2) dp[i][i][j] = 0;

    rep(i, n){
        rep(l, n - i){
            int r = l + i;
            if(l > 0){
                dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][0] + (c[l] != c[l-1]));
                dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][1] + (c[r] != c[l-1]));
            }
            if(r < n - 1){
                dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][0] + (c[l] != c[r+1]));
                dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][1] + (c[r] != c[r+1]));
            }
        }
    }
    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endl;

    return 0;
}
