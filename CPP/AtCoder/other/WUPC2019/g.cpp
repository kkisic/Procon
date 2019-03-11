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

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    //s[i][j] : [0, j)にiが何個あるか
    auto s = initVec2<int>(n, m + 1);
    rep(i, m){
        s[a[i]][i+1] = 1;
    }
    rep(i, n){
        rep(j, m){
            s[i][j+1] += s[i][j];
        }
    }

    //d[i][j] : 全てのjの後ろにあるiの個数の総和
    auto d = initVec2<int>(n, n);
    rep(i, n){
        rep(j, n){
            if(i == j){
                continue;
            }
            rep(k, m){
                if(a[k] != i){
                    continue;
                }
                d[i][j] += s[j][m] - s[j][k];
            }
        }
    }

    //dp[s] : 集合sに対する最小値
    vector<int> dp(1LL << n, INF);
    dp[0] = 0;
    rep(s, 1LL << n){
        rep(i, n){
            if((s >> i) % 2){
                continue;
            }
            int t = s | (1 << i);

            int sum = 0;
            rep(j, n){
                if((s >> j) % 2){
                    continue;
                }
                sum += d[j][i];
            }
            dp[t] = min(dp[t], dp[s] + sum);
        }
    }
    cout << dp[(1LL<<n)-1] << endl;

    return 0;
}
