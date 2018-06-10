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

    vector<vector<int>> dp(3, vector<int>(n+1));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[1][i] = dp[0][i-1];
        if(i >= 2){
            dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % MOD;
            dp[2][i] = dp[0][i-2];
        }
    }
    int ans = ((dp[0][n] + dp[1][n]) % MOD + dp[2][n]) % MOD;
    cout << ans << endl;

    return 0;
}
