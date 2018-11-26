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
const int N = 1000;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> a(t+1);
    rep(i, t) cin >> a[i+1];

    vector<vector<int>> dp(t+1, vector<int>(N));
    dp[0][0] = 1;
    for(int i = 0; i < t; i++){
        for(int j = 0; j <= N; j++){
            if(j % 2 != 0){
                continue;
            }
            for(int k = 0; k <= a[i+1]; k++){
                dp[i+1][k+j/2] = (dp[i+1][k+j/2] + dp[i][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i *= 2){
        ans = (ans + dp[t][i]) % MOD;
    }
    for(int i = 1; i < t; i++){
        ans = (ans + dp[i][1]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
