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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(100001, INF));
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 100000){
            if(dp[i][j] == INF){
                continue;
            }
            dp[i+1][j+a[i]] = min(dp[i+1][j+a[i]], dp[i][j]);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b[i]);
        }
    }

    int ans = INF;
    rep(j, 100001){
        if(ans > max(dp[n][j], j)){
            ans = max(dp[n][j], j);
        }
    }
    cout << ans << endl;

    return 0;
}
