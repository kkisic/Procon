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
    int h, a, d;
    cin >> h >> a >> d;

    vector<double> dp(h+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= h; i++){
        if(i >= a && dp[i-a] != INF){
            dp[i] = min(dp[i], dp[i-a] + 1);
        }else{
            dp[i] = min(dp[i], dp[0] + 1);
        }
        if(i >= d && dp[i-d] != INF){
            dp[i] = min(dp[i], dp[i-d] + 1.5);
        }else{
            dp[i] = min(dp[i], dp[0] + 1.5);
        }
    }
    cout << dp[h] << endl;

    return 0;
}
