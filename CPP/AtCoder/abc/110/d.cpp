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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

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
            if(n < k){
                return 0;
            }
            return factM(n) * t[k] % MOD * t[n-k] % MOD;
        }
};

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> p = prime(100000);
    vector<int> fact((int)p.size());
    int x = m;

    rep(i, (int)p.size()){
        while(x % p[i] == 0){
            fact[i]++;
            x /= p[i];
        }
    }
    if(x != 1){
        p.push_back(0);
        fact.push_back(1);
    }

    combination c(n + 1000);
    int ans = 1;
    rep(i, (int)p.size()){
        if(fact[i] == 0){
            continue;
        }
        int tmp = c.comb(fact[i] + n - 1, fact[i]);
        ans = ans * tmp % MOD;
    }
    cout << ans << endl;

    return 0;
}
