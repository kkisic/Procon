#include <vector>
#include <algorithm>
#include <iostream>

#define int long long int

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> sum(n+1);
    sum[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }

    if(sum[n] == k){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n+1, 1e10));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            int c = a[i] * dp[i-1][j-1] / sum[i];
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + c + 1);
        }
    }

    int ans, d;
    d = 0;
    for(int i = 0; i <= n; i++){
        if(d < dp[n-1][i] && dp[n-1][i] <= k){
            d = dp[n-1][i];
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
