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
    int n, d;
    cin >> n >> d;

    vector<int> tokyo(n), kyoto(n);
    rep(i, n){
        cin >> tokyo[i] >> kyoto[i];
    }

    vector<vector<int>> dp(2, vector<int>(n+1));
    dp[0][1] = tokyo[0];
    dp[1][1] = kyoto[0] - d;
    for(int i = 2; i <= n; i++){
        dp[0][i] = max(dp[0][i-1] + tokyo[i-1], dp[1][i-1] + tokyo[i-1] - d);
        dp[1][i] = max(dp[1][i-1] + kyoto[i-1], dp[0][i-1] + kyoto[i-1] - d);
    }
    cout << max(dp[0][n], dp[1][n]) << endl;

    return 0;
}
