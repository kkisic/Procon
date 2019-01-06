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

    int n, cap;
    cin >> n >> cap;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    vector<vector<int>> dp(n+1, vector<int>(1e5 + 1, INF));
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 1e5){
            if(dp[i][j] == INF){
                continue;
            }
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j + v[i] > 1e5){
                continue;
            }
            dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j] + w[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= 1e5; i++){
        if(dp[n][i] <= cap){
            ans = max(ans, i);
        }
    }
    cout << ans << endl;

    return 0;
}
