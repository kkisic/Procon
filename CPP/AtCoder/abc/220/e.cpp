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

    int n, d;
    cin >> n >> d;

    vector<int> dep(n), sum(n);
    dep[0] = 1;
    sum[0] = dep[0];
    rep(i, n - 1){
        dep[i+1] = dep[i] * 2 % MOD;
        sum[i+1] = (sum[i] + dep[i+1]) % MOD;
    }

    int ans = 0;
    for(int l = 0; l <= d; l++){
        if(l > n - 1 || d - l > n - 1) continue;
        ans += dep[max(0LL, l-1)] * dep[max(0LL, d-l-1)] % MOD * sum[n-1-max(l, d-l)] % MOD;
        ans %= MOD;
    }
    cout << ans * 2 % MOD << endl;

    return 0;
}
