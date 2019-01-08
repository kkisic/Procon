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

    string s;
    int d;
    cin >> s >> d;
    int n = SZ(s);

    vector<int> num(n);
    rep(i, n){
        num[i] = s[i] - '0';
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d, vector<int>(2)));
    dp[0][0][1] = 1;
    rep(i, n){
        rep(j, d){
            rep(k, 10){
                dp[i+1][(j+k)%d][0] += dp[i][j][0];
                dp[i+1][(j+k)%d][0] %= MOD;
            }
            rep(k, num[i]){
                dp[i+1][(j+k)%d][0] += dp[i][j][1];
                dp[i+1][(j+k)%d][0] %= MOD;
            }
            dp[i+1][(j+num[i])%d][1] += dp[i][j][1];
            dp[i+1][(j+num[i])%d][1] %= MOD;
        }
    }

    int ans = (dp[n][0][0] + dp[n][0][1]) % MOD;
    ans = (ans + MOD - 1) % MOD;
    cout << ans << endl;

    return 0;
}
