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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto dp = initVec2<int>(n + 1, 5);
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 5){
            if(j <= 0){
                dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
            }
            if(j <= 1){
                dp[i+1][1] = max(dp[i+1][1], dp[i][j] + a[i]);
            }
            if(j <= 2){
                dp[i+1][2] = max(dp[i+1][2], dp[i][j] + a[i] * x);
            }
            if(j <= 3){
                dp[i+1][3] = max(dp[i+1][3], dp[i][j] + a[i]);
            }
            dp[i+1][4] = max(dp[i+1][4], dp[i][j]);
        }
    }

    int ans = 0;
    rep(i, 5){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
