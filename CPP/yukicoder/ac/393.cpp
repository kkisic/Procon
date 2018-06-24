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
    int d;
    cin >> d;

    while(d > 0){
        int n1, n2, m;
        cin >> n1 >> n2 >> m;

        vector<int> a(m);
        rep(i, m) cin >> a[i];
        sort(a.begin(), a.end());

        vector<int> s(m);
        s[0] = a[0];
        for(int i = 1; i < m; i++){
            s[i] = s[i-1] + a[i];
        }

        vector<vector<int>> dp(m+1, vector<int>(n1+1, -1));
        dp[0][0] = 0;
        rep(i, m){
            rep(j, n1+1){
                if(dp[i][j] == -1){
                    continue;
                }

                if(j + a[i] <= n1){
                    dp[i+1][j+a[i]] = dp[i][j] + 1;
                }

                if(s[i] - j <= n2){
                    dp[i+1][j] = dp[i][j] + 1;
                }
            }
        }

        int ans = 0;
        rep(i, m+1){
            rep(j, n1+1){
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                }
            }
        }
        cout << ans << endl;

        d--;
    }

    return 0;
}
