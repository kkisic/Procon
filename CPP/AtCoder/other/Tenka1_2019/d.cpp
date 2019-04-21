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
const int MOD = 998244353;

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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;
    rep(i, n){
        sum += a[i];
    }

    auto dp1 = initVec2<int>(n + 1, sum + 1);
    dp1[0][0] = 1;
    rep(i, n){
        rep(j, sum){
            dp1[i+1][j] += dp1[i][j];
            dp1[i+1][j] %= MOD;;
            if(j + a[i] > sum){
                continue;
            }
            dp1[i+1][j+a[i]] += dp1[i][j];
            dp1[i+1][j+a[i]] %= MOD;
        }
    }

    auto dp2 = initVec2<int>(n + 1, sum + 1);
    dp2[0][0] = 1;
    rep(i, n){
        rep(j, sum){
            dp2[i+1][j] += dp2[i][j] * 2 % MOD;
            dp2[i+1][j] %= MOD;;
            if(j + a[i] > sum){
                continue;
            }
            dp2[i+1][j+a[i]] += dp2[i][j];
            dp2[i+1][j+a[i]] %= MOD;
        }
    }

    int ans = 1;
    rep(i, n){
        ans *= 3;
        ans %= MOD;
    }

    int x = 0;
    for(int i = (sum + 1) / 2; i <= sum; i++){
        x += dp2[n][i];
        x %= MOD;
    }
    if(sum % 2 == 0){
        x = (x + MOD - dp1[n][sum/2]) % MOD;
    }
    x *= 3;
    x %= MOD;

    cout << (ans + MOD - x) % MOD << endl;

    return 0;
}
