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

class combination{
    private:
        vector<int> t;

    public:
        combination(int n): t(n+1){
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

    int k, n;
    cin >> k >> n;

    combination c(4000);

    for(int t = 2; t <= 2 * k; t++){
        int ans = 0;
        int p = 0;
        for(int i = 1; i <= t / 2; i++){
            if(t - i <= k && i != t - i){
                p++;
            }
        }

        rep(q, p+1){
            int tmp = c.comb(p, q) * powM(2, q) % MOD;

            if(t % 2 != 0){
                //(n - 2 * p + q) H (n - q)
                tmp = tmp * c.comb(k-2*p+n-1, n-q) % MOD;
            }else{
                //(n - 2 * p - 1 + q) H (n - q)
                //(n - 2 * p - 1 + q) H (n - q - 1)
                int x = c.comb(k-2*p+n-2, n-q) + c.comb(k-2*p+n-3, n-q-1) % MOD;
                tmp = tmp * x % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
