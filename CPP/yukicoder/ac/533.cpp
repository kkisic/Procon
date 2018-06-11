#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> dp(3, vector<int>(n+3));
    dp[0][1] = 1;
    dp[1][2] = 1;
    dp[2][3] = 1;
    for(int i = 2; i <= n; i++){
        dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % MOD;
        if(i >= 3){
            dp[1][i] = (dp[0][i-2] + dp[2][i-2]) % MOD;
        }
        if(i >= 4){
            dp[2][i] = (dp[0][i-3] + dp[1][i-3]) % MOD;
        }
    }

    int ans = ((dp[0][n] + dp[1][n]) % MOD + dp[2][n]) % MOD;
    cout << ans << endl;

    return 0;
}
