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
    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int> a(n);
        rep(i, n) cin >> a[i];

        vector<vector<bool>> able(n, vector<bool>(n, false));
        rep(i, n-1){
            if(abs(a[i] - a[i+1]) < 2){
                able[i][i+1] = true;
            }
        }
        for(int d = 3; d < n; d += 2){
            rep(i, n){
                if(i + d >= n){
                    continue;
                }

                if(i + 1 < i + d - 1 && able[i+1][i+d-1] && abs(a[i] - a[i+d]) < 2){
                    able[i][i+d] = true;
                    continue;
                }

                for(int k = i+1; k < i + d - 1; k++){
                    if(able[i][k] && able[k+1][i+d]){
                        able[i][i+d] = true;
                        break;
                    }
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(n));
        rep(i, n){
            rep(j, n){
                if(able[i][j]){
                    dp[i][j] = j - i + 1;
                }
            }
        }

        rep(i, n){
            for(int j = i+1; j < n; j++){
                for(int k = i; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }

    return 0;
}
