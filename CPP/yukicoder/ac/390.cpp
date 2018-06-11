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
    sort(a.begin(), a.end());

    vector<int> dp(1e6 + 1);
    rep(i, n){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j != 0){
                continue;
            }
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
            if(j != 1){
                dp[a[i]] = max(dp[a[i]], dp[a[i] / j] + 1);
            }
        }
    }
    int ans = 0;
    rep(i, 1e6+1){
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    cout << ans << endl;

    return 0;
}
