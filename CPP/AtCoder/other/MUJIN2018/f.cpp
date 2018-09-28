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
            if(n < k){
                return 0;
            }
            return factM(n) * t[k] % MOD * t[n-k] % MOD;
        }

        int getInv(int n){
            return t[n];
        }
};

signed main(){
    int n;
    cin >> n;

    vector<int> g(n+1);
    rep(i, n){
        int a;
        cin >> a;
        g[a]++;
    }

    combination c(n * 2);

    vector<vector<int>> dp(n+2, vector<int>(n+1));
    dp[n+1][0] = 1;

    for(int i = n+1; i > 1; i--){
        for(int j = n; j >= 0; j--){
            if(dp[i][j] == 0){
                continue;
            }

            int num = j + g[i-1];
            for(int k = 0; num - (i-1) * k >= 0; k++){
                int p = factM(num) * c.getInv(num - (i-1) * k) % MOD;
                p = p * c.getInv(k) % MOD;
                p = p * powM(c.getInv(i-1), k) % MOD;

                dp[i-1][num-(i-1)*k] = (dp[i-1][num-(i-1)*k] + dp[i][j] * p) % MOD;
            }
        }
    }

    cout << dp[1][0] << endl;

    return 0;
}
