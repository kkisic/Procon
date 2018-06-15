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
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    vector<bool> dp(10001, false);
    dp[0] = true;
    rep(i, n){
        for(int j = 10000; j >= 0; j--){
            if(j < p[i]){
                continue;
            }
            dp[j] = dp[j] || dp[j-p[i]];
        }
    }

    int ans = 0;
    rep(i, 10001){
        if(dp[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}
