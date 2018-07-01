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

    vector<int> dp(W+1, -1);
    dp[0] = 0;
    rep(i, n){
        rep(j, W+1){
            if(j < w[i] || dp[j-w[i]] == -1){
                continue;
            }
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    int ans = 0;
    rep(i, W+1){
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    cout << ans << endl;

    return 0;
}
