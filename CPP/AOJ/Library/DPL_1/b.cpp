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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, W;
    cin >> n >> W;

    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    rep(i, W+1){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= 0; j--){
            if(j < w[i-1]){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
        }
    }
    cout << dp[n][W] << endl;

    return 0;
}
