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

int factM(int n){
    static vector<int> t = {1};

    if((int)t.size() > n){
        return t[n];
    }

    for(int i = t.size(); i <= n; i++){
        t.push_back(t[i-1] * i % MOD);
    }
    return t[n];
}

class Combination{
    private:
        vector<int> t;

    public:
        Combination(int n): t(n+1){
            t[n] = powM(factM(n), MOD-2);

            for(int i = n-1; i >= 0; i--){
                t[i] = t[i+1] * (i+1) % MOD;
            }
        }

        int comb(int n, int k){
            if(n < k || n < 0 || k < 0){
                return 0;
            }
            return factM(n) * t[k] % MOD * t[n-k] % MOD;
        }

        int getInv(int n){
            return t[n];
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    if(n < m){
        swap(n, m);
    }

    Combination c(200000);
    int p = c.comb(n * m - 2, k - 2);

    int ans = 0;
    for(int i = 1; i < n; i++){
        ans += i * m % MOD * m % MOD * (n - i) % MOD * p % MOD;
        ans %= MOD;
    }
    for(int i = 1; i < m; i++){
        ans += i * n % MOD * n % MOD * (m - i) % MOD * p % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
