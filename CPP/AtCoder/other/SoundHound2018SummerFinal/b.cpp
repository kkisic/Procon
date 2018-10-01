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

    vector<int> b(n);
    rep(i, n) cin >> b[i];

    //[0, i)
    vector<int> dp(n+1), best(n+1);
    for(int i = 1; i <= n; i++){
        if(i < k){
            dp[i] = dp[i-1] + b[i-1];
            best[i] = max(best[i-1], dp[i]);
            continue;
        }

        dp[i] = max(dp[i-1] + b[i-1], best[i-k]);
        best[i] = max(best[i-1], dp[i]);
    }
    cout << dp[n] << endl;

    return 0;
}
