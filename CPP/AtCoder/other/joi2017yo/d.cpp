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
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        a[i]--;
    }

    auto c = initVec2<int>(m, n + 1);
    vector<int> eq(m);
    rep(i, n){
        rep(j, m){
            if(a[i] == j){
                eq[j]++;
                c[j][i+1] = c[j][i];
            }else{
                c[j][i+1] = c[j][i] + 1;
            }
        }
    }

    vector<int> dp(1 << m, INF);
    vector<int> sum(1 << m);
    dp[0] = 0;
    rep(s, 1 << m){
        rep(i, m){
            if((s >> i) % 2){
                continue;
            }
            sum[s^(1<<i)] = sum[s] + eq[i];
            dp[s^(1<<i)] = min(dp[s^(1<<i)], dp[s] + c[i][sum[s]+eq[i]] - c[i][sum[s]]);
        }
    }
    cout << dp[(1<<m)-1] << endl;

    return 0;
}
