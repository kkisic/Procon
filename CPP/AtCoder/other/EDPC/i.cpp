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

    int n;
    cin >> n;
    vector<double> p(n);
    rep(i, n) cin >> p[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1.0;
    rep(i, n){
        for(int j = 0; j <= i; j++){
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double ans = 0;
    for(int i = n / 2 + 1; i <= n; i++){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
