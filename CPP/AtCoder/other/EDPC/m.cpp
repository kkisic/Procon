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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    rep(i, n){
        rep(j, k){
            dp[i][j+1] += dp[i][j];
            dp[i][j+1] %= MOD;
        }
        rep(j, k + 1){
            int culc = dp[i][j] + MOD;
            if(j - a[i] > 0){
                culc -= dp[i][j-a[i]-1];
            }
            culc %= MOD;;
            dp[i+1][j] += culc;
            dp[i+1][j] %= MOD;
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}
