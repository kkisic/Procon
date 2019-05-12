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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto dp = initVec2<int>(1 << 20, 2);
    vector<int> cnt(1 << 20);
    int sum = 0;
    int x = 0;
    set<int> s;

    rep(i, 1 << 20){
        dp[i][0] = 1;
    }

    rep(i, n){
        x ^= a[i];
        s.insert(x);
        if(x == 0){
            sum++;
        }else{
            dp[x][0] += dp[x][1] * (sum - cnt[x]) % MOD;
            dp[x][0] %= MOD;
            dp[x][1] += dp[x][0];
            dp[x][1] %= MOD;
            cnt[x] = sum;
        }
    }

    if(x == 0){
        int ans = 0;
        for(int x : s){
            ans += dp[x][1];
            ans %= MOD;
        }
        ans += powM(2, sum - 1);
        ans %= MOD;
        cout << ans << endl;
    }else{
        cout << dp[x][0] << endl;
    }

    return 0;
}
