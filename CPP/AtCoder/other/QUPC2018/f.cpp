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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(1 << n);
    dp[0] = 1;
    rep(s, (1 << n) - 1){
        if(dp[s] == 0){
            continue;
        }
        int p1 = -1;
        rep(i, n){
            if((s >> i) % 2 == 0){
                p1 = i;
                break;
            }
        }
        int sum = a[p1];
        int t = 1 << p1;
        dp[s^t] += dp[s];

        for(int p2 = p1 + 1; p2 < n; p2++){
            if((s >> p2) % 2){
                continue;
            }
            sum += a[p2];
            t ^= 1 << p2;
            if((sum + 1) / 2 <= k){
                dp[s^t] += dp[s];
            }

            for(int p3 = p2 + 1; p3 < n; p3++){
                if((s >> p3) % 2){
                    continue;
                }
                sum += a[p3];
                t ^= 1 << p3;
                if((sum + 2) / 3 <= k){
                    dp[s^t] += dp[s];
                }

                sum -= a[p3];
                t ^= 1 << p3;
            }

            sum -= a[p2];
            t ^= 1 << p2;
        }
    }
    cout << dp[(1<<n)-1] << endl;

    return 0;
}
