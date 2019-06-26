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

    int n, m;
    cin >> n >> m;

    bool neg = false;
    if(n < 0){
        neg = true;
        n = abs(n);
    }

    Combination c(200000);
    vector<int> p = prime(100000);
    vector<int> x;

    rep(i, SZ(p)){
        if(n % p[i] == 0){
            x.push_back(0);
            while(n % p[i] == 0){
                x.back()++;
                n /= p[i];
            }
        }
    }
    if(n != 1){
        x.push_back(1);
    }

    int ans1 = 1;
    for(int a : x){
        ans1 *= c.comb(a + m - 1, a);
        ans1 %= MOD;
    }

    int ans2 = 0;
    for(int i = 0; i <= m; i++){
        if((neg && i % 2) || (not neg && i % 2 == 0)){
            ans2 += c.comb(m, i);
            ans2 %= MOD;
        }
    }

    cout << ans1 * ans2 % MOD << endl;

    return 0;
}
