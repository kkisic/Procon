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
const int MOD = 1e9;

signed main(){
    int n, m;
    cin >> n >> m;
    n /= 1000;
    n %= m;

    vector<int> dp(m+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1; i < m; i++){
        for(int j = i; j >= 0; j--){
            dp[j+1] = (dp[j+1] + dp[j]) % MOD;
        }
    }
    cout << dp[n] % 1000000000 << endl;

    return 0;
}
