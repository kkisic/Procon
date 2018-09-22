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

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> x(n, 0);
    int sum = 0;
    rep(i, n){
        int t = a[i];

        while(t > 0){
            t /= 2;
            x[i]++;
        }
        sum += x[i];
    }

    int m = min(5000LL, k);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2)));
    dp[0][0][0] = 1;
    rep(i, n){
        rep(j, m+1){
            rep(l, 2){
                if(dp[i][j][l] == 0){
                    continue;
                }

                int limit = min(j + x[i], m);
                for(int t = j; t <= limit; t++){
                    if(t == j + x[i]){
                        dp[i+1][t][1] = (dp[i+1][t][1] + dp[i][j][l]) % MOD;
                        continue;
                    }
                    dp[i+1][t][l] = (dp[i+1][t][l] + dp[i][j][l]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    rep(i, m+1){
        ans = (ans + dp[n][i][1]) % MOD;
    }
    if(k == m){
        ans = (ans + dp[n][k][0]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
