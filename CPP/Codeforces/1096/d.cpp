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
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    string h = "hard";
    vector<vector<int>> dp(n + 1, vector<int>(5, INF));
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 4){
            if(s[i] == h[j]){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i]);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            }else{
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }

    int ans = INF;
    rep(i, 4){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
