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
    int n, x;
    cin >> n >> x;

    vector<int> t(n+1);
    t[0] = 0;
    rep(i, n) cin >> t[i+1];

    vector<int> next(n);
    rep(i, n){
        auto it = lower_bound(t.begin(), t.end(), t[i] + x);
        if(it == t.end()){
            next[i] = n;
        }else{
            next[i] = it - t.begin();
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rep(i, n){
        dp[i+1][1] = x;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[next[i]][j+1] = max(dp[next[i]][j+1], dp[i][j]);
            dp[next[i]-1][j+1] = max(dp[next[i]-1][j+1], dp[i][j]);
            if(next[i] > i){
                int st = min(t[next[i]] - t[i], x);
                dp[next[i]][j+1] = max(dp[next[i]][j+1], dp[i][j] + st);
            }
            if(next[i] - 1 > i){
                int st = min(t[next[i]-1] - t[i], x);
                dp[next[i]-1][j+1] = max(dp[next[i]-1][j+1], dp[i][j] + st);
            }
        }
    }

    rep(i, n){
        int ans = 0;
        rep(j, n){
            if(ans < dp[j+1][i+1]){
                ans = dp[j+1][i+1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
