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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
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

    int n, k;
    cin >> n >> k;

    vector<int> p = prime(4e7);
    vector<int> factor;
    map<int, int> mm;
    int tmp = n;
    rep(i, SZ(p)){
        if(tmp % p[i] != 0){
            continue;
        }
        factor.push_back(p[i]);
        mm[p[i]] = 0;
        while(tmp % p[i] == 0){
            mm[p[i]]++;
            tmp /= p[i];
        }
    }
    if(tmp != 1){
        factor.push_back(tmp);
        mm[tmp] = 1;
    }

    int cnt = 1;
    for(int x : factor){
        cnt *= mm[x] + 1;
    }

    vector<int> inv(60);
    rep(i, 60){
        inv[i] = powM(i, MOD-2);
    }

    int ans = 1;
    for(int x : factor){
        vector<vector<int>> dp(k + 1, vector<int>(mm[x]+1));
        dp[0][mm[x]] = 1;
        rep(i, k){
            for(int j = 0; j <= mm[x]; j++){
                for(int l = 0; l <= j; l++){
                    dp[i+1][l] += dp[i][j] * inv[j+1] % MOD;
                    dp[i+1][l] %= MOD;
                }
            }
        }

        int tmp = 0;
        rep(i, mm[x] + 1){
            tmp += powM(x, i) * dp[k][i];
            tmp %= MOD;
        }
        ans *= tmp;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
