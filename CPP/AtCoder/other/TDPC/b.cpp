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
    int A, B;
    cin >> A >> B;
    vector<int> a(A), b(B);
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];

    vector<vector<int>> dp(A+1, vector<int>(B+1));
    dp[A][B] = 0;
    for(int i = A; i >= 0; i--){
        for(int j = B; j >= 0; j--){
            if(i == A && j == B){
                continue;
            }
            if((i + j) % 2 == 0){
                if(i == A){
                    dp[i][j] = dp[i][j+1] + b[j];
                    continue;
                }
                if(j == B){
                    dp[i][j] = dp[i+1][j] + a[i];
                    continue;
                }
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j+1] + b[j]);
            }else{
                if(i == A){
                    dp[i][j] = dp[i][j+1];
                    continue;
                }
                if(j == B){
                    dp[i][j] = dp[i+1][j];
                    continue;
                }
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[0][0] << endl;

    return 0;
}
