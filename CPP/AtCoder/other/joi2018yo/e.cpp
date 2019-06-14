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
    auto a = initVec2<int>(h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];

    auto dp = initVec3<int>(h, w, h * w + 1, INF);
    dp[0][0][0] = 0;

    vector<int> d = {1, 0, -1, 0};
    rep(k, h * w) rep(i, h) rep(j, w){
        rep(l, 4){
            int x = i + d[l];
            int y = j + d[l^1];
            if(x < 0 || x >= h || y < 0 || y >= w){
                continue;
            }
            dp[x][y][k+1] = min(dp[x][y][k+1], dp[i][j][k] + (k * 2 + 1) * a[x][y]);
        }
    }

    int ans = INF;
    rep(i, h * w + 1){
        ans = min(ans, dp[h-1][w-1][i]);
    }
    cout << ans << endl;

    return 0;
}
