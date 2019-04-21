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

    int n, k;
    cin >> n >> k;
    auto c = initVec2<int>(10, 0);

    rep(i, n){
        int x, y;
        cin >> x >> y;
        c[y-1].push_back(x);
    }

    vector<vector<int>> sc(10);
    rep(i, 10){
        sc[i] = vector<int>(SZ(c[i]) + 1);
        sort(ALL(c[i]), greater<int>());
        rep(j, SZ(c[i])) sc[i][j+1] = sc[i][j] + c[i][j] + 2 * j;
    }

    auto dp = initVec2<int>(11, k + 1, -INF);
    dp[0][0] = 0;
    rep(i, 10){
        rep(j, k + 1){
            rep(l, SZ(sc[i])){
                if(j + l > k){
                    continue;
                }
                dp[i+1][j+l] = max(dp[i+1][j+l], dp[i][j] + sc[i][l]);
            }
        }
    }
    cout << dp[10][k] << endl;

    return 0;
}
