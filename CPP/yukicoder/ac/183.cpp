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

    vector<bool> dp(1 << 15);
    dp[0] = true;
    rep(j, n){
        for(int i = 1; i < (1 << 15); i++){
            if(dp[i^a[j]]){
                dp[i] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << 15); i++){
        if(dp[i]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
