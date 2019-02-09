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
    vector<int> a(n+2);
    rep(i, n) cin >> a[i+1];
    n += 2;

    auto dp = initVec2<int>(n + 1, 5, INF);
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 5){
            for(int k = j; k < 5; k++){
                if(k == 0 || k == 4){
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + a[i]);
                    continue;
                }
                if(k == 2){
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + (a[i] + 1) % 2);
                    continue;
                }
                if(a[i] != 0){
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + a[i] % 2);
                }else{
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + 2);
                }
            }
        }
    }

    cout << dp[n][4] << endl;

    return 0;
}
