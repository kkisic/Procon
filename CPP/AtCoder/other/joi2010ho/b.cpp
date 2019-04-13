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

    int n;
    cin >> n;
    vector<int> c(n + 1);
    rep(i, n - 1) cin >> c[i+1];

    auto dp = initVec3<int>(2, n + 1, 2, INF);
    dp[0][0][0] = 0;
    int x = 0;
    int y = 1;

    rep(i, n){
        rep(j, n / 2 + 1) rep(k, 2){
            dp[y][j][k] = INF;
        }
        rep(j, n / 2){
            rep(k, 2){
                if(k == 0){
                    dp[y][j+1][0] = min(dp[y][j+1][0], dp[x][j][0] + c[i+1] - c[i]);
                    dp[y][j][1] = min(dp[y][j][1], dp[x][j][0] + c[i+1]);
                }else{
                    dp[y][j][1] = min(dp[y][j][1], dp[x][j][1] + c[i+1] - c[i]);
                    dp[y][j+1][0] = min(dp[y][j+1][0], dp[x][j][1] + c[i+1]);
                }
            }
        }
        swap(x, y);
    }
    cout << min(dp[x][n/2][0], dp[x][n/2][1]) << endl;

    return 0;
}
