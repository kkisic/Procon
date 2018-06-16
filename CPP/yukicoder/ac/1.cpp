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
    int n, c, v;
    cin >> n >> c >> v;

    vector<int> s(v), t(v), y(v), m(v);
    rep(i, v){
        cin >> s[i];
    }
    rep(i, v){
        cin >> t[i];
    }
    rep(i, v){
        cin >> y[i];
    }
    rep(i, v){
        cin >> m[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(c+1, INF));
    dp[1][c] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= c; j++){
            rep(k, v){
                if(s[k] != i || y[k] > j || dp[i][j] == INF){
                    continue;
                }

                dp[t[k]][j-y[k]] = min(dp[t[k]][j-y[k]], dp[i][j] + m[k]);
            }
        }
    }

    int ans = INF;
    rep(i, c+1){
        if(dp[n][i] < ans){
            ans = dp[n][i];
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout  << ans << endl;
    }

    return 0;
}
