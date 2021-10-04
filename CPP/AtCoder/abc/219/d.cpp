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

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    auto dp = initVec3(n + 1, x + 1, y + 1, INF);
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, x + 1) {
            rep(k, y + 1) {
                dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
                int nx = min(j + a[i], x);
                int ny = min(k + b[i], y);
                dp[i+1][nx][ny] = min(dp[i][j][k] + 1, dp[i+1][nx][ny]);
            }
        }
    }

    if (dp[n][x][y] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x][y] << endl;
    }

    return 0;
}
