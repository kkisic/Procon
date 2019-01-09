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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int l = 1; l <= n; l++){
        for(int i = 0; i + l <= n; i++){
            if((n - l) % 2 == 0){
                dp[i][i+l] = -INF;
            }else{
                dp[i][i+l] = INF;
            }
        }
    }

    rep(l, n + 1){
        rep(i, n){
            if(i + l > n){
                continue;
            }
            int j = i + l;
            if((n - l) % 2 == 1){
                if(i - 1 >= 0){
                    dp[i-1][j] = max(dp[i-1][j], dp[i][j] + a[i-1]);
                }
                if(j + 1 <= n){
                    dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[j]);
                }
            }else{
                if(i - 1 >= 0){
                    dp[i-1][j] = min(dp[i-1][j], dp[i][j] - a[i-1]);
                }
                if(j + 1 <= n){
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] - a[j]);
                }
            }
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}
