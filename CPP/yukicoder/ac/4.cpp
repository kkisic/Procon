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
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    vector<bool> dp(10001, false);
    dp[0] = true;
    rep(i, n){
        for(int j = 10000; j >= 1; j--){
            if(j < w[i]){
                continue;
            }
            dp[j] = dp[j] || dp[j-w[i]];
        }
    }
    int sum = 0;
    rep(i, n) sum += w[i];
    if(sum % 2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    sum /= 2;
    if(dp[sum]){
        cout << "possible" << endl;
    }else{
        cout << "impossible" << endl;
    }

    return 0;
}
