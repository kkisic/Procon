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

    int n, A, B;
    cin >> n >> A >> B;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    auto dp = initVec3<int>(n + 1, 401, 401, INF);
    dp[0][0][0] = 0;
    rep(i, n){
        rep(j, 401){
            rep(k, 401){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if(j + a[i] > 400 || k + b[i] > 400){
                    continue;
                }
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
            }
        }
    }

    int aa = A;
    int bb = B;
    int ans = INF;
    while(aa <= 400 && bb <= 400){
        ans = min(ans, dp[n][aa][bb]);
        aa += A;
        bb += B;
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
