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
    vector<vector<int>> a(n, vector<int>(3));
    rep(i, n) rep(j, 3) cin >> a[i][j];

    vector<vector<int>> dp(n + 1, vector<int>(3));
    rep(i, n){
        rep(j, 3){
            rep(k, 3){
                if(j == k){
                    continue;
                }
                dp[i+1][k] = max(dp[i+1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    int ans = 0;
    rep(i, 3){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
