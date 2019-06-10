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

    int n, t, s;
    cin >> n >> t >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    auto dp1 = initVec2<int>(n + 1, t + 1);
    rep(i, n){
        rep(j, t){
            dp1[i+1][j] = max(dp1[i+1][j], dp1[i][j]);
            if(j + b[i] > t){
                continue;
            }
            dp1[i+1][j+b[i]] = max(dp1[i+1][j+b[i]], dp1[i][j] + a[i]);
        }
    }

    reverse(ALL(a));
    reverse(ALL(b));

    auto dp2 = initVec2<int>(n + 1, t + 1);
    rep(i, n){
        rep(j, t){
            dp2[i+1][j] = max(dp2[i+1][j], dp2[i][j]);
            if(j + b[i] > t){
                continue;
            }
            dp2[i+1][j+b[i]] = max(dp2[i+1][j+b[i]], dp2[i][j] + a[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp1[i][s] + dp2[n-i][t-s]);
    }
    cout << ans << endl;

    return 0;
}
