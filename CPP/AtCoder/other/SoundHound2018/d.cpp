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

    int h, w;
    cin >> h >> w;

    auto p = initVec2<int>(h + 1, w + 1);
    rep(i, h) rep(j, w) cin >> p[i+1][j+1];
    auto f = initVec2<int>(h + 1, w + 1);
    rep(i, h) rep(j, w) cin >> f[i+1][j+1];

    auto dp = initVec2<int>(h + 2, w + 1, -INF);
    dp[1][1] = 0;
    for(int i = 1; i <= h; i++){
        vector<int> a(w + 2); //[1, i)
        vector<int> b(w + 2); //(i, w]

        for(int j = 2; j <= w; j++){
            a[j] = max(a[j-1] + p[i][j-1] - f[i][j-1] * 2, p[i][j-1] - f[i][j-1]);
        }
        for(int j = w - 1; j >= 1; j--){
            b[j] = max(b[j+1] + p[i][j+1] - f[i][j+1] * 2, p[i][j+1] - f[i][j+1]);
        }

        int maxi = -INF;
        for(int j = 1; j <= w; j++){
            maxi = max(maxi + p[i][j] - f[i][j], dp[i][j] + a[j] + p[i][j] - f[i][j] * 2);
            maxi = max(maxi, dp[i][j] + p[i][j] - f[i][j]);
            dp[i+1][j] = max(dp[i+1][j], maxi + b[j] - f[i][j]);
            dp[i+1][j] = max(dp[i+1][j], maxi);
        }
        maxi = -INF;
        for(int j = w; j >= 1; j--){
            maxi = max(maxi + p[i][j] - f[i][j], dp[i][j] + b[j] + p[i][j] - f[i][j] * 2);
            maxi = max(maxi, dp[i][j] + p[i][j] - f[i][j]);
            dp[i+1][j] = max(dp[i+1][j], maxi + a[j] - f[i][j]);
            dp[i+1][j] = max(dp[i+1][j], maxi);
        }
    }

    for(int i = 1; i <= w; i++){
        cout << dp[h+1][i] << endl;
    }
    return 0;
}
