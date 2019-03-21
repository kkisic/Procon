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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    vector<int> p = prime(m);

    vector<int> cnt(m + 1, -1);
    cnt[1] = 0;
    rep(i, SZ(p)){
        for(int j = m / p[i]; j >= 1; j--){
            if(cnt[j] >= 0){
                cnt[j*p[i]] = cnt[j] + 1;
            }
        }
    }

    int ans = 1;
    for(int i = 2; i <= m; i++){
        if(cnt[i] <= 0){
            continue;
        }
        int x = m / i;
        int t = x * powM(m - x, MOD - 2) % MOD;
        if(cnt[i] % 2 == 0){
            ans += MOD - t;
        }else{
            ans += t;
        }
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
