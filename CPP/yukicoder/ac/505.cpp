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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = a[0];
    dp[1][0] = a[0];

    for(int i = 1; i < n; i++){
        vector<int> s;
        s.push_back(dp[0][i-1] + a[i]);
        s.push_back(dp[0][i-1] - a[i]);
        s.push_back(dp[0][i-1] * a[i]);
        s.push_back(dp[1][i-1] + a[i]);
        s.push_back(dp[1][i-1] - a[i]);
        s.push_back(dp[1][i-1] * a[i]);
        if(a[i] != 0){
            s.push_back(dp[0][i-1] / a[i]);
            s.push_back(dp[1][i-1] / a[i]);
        }
        dp[0][i] = *min_element(s.begin(), s.end());
        dp[1][i] = *max_element(s.begin(), s.end());
    }
    cout << dp[1][n-1] << endl;

    return 0;
}
