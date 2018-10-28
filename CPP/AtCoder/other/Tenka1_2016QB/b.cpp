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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s;
    cin >> s;

    int len = s.length();
    vector<int> diff(len+1);
    rep(i, len){
        diff[i+1] = diff[i] + (s[i] == '(' ? 1 : -1);
    }

    vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(len+1, vector<int>(len+1, INF)));
    dp[0][0][0] = 0;

    rep(i, len){
        rep(j, len){
            rep(k, len+1){
                if(dp[i][j][k] == INF){
                    continue;
                }

                if(s[i] == '('){
                    //変更しない
                    dp[i+1][j][k+1] = min(dp[i+1][j][k+1], dp[i][j][k]);
                    //変更する
                    if(k > 0){
                        dp[i+1][i][k-1] = min(dp[i+1][i][k-1], dp[i][j][k] + 1);
                    }
                }else{
                    //変更する
                    dp[i+1][i][k+1] = min(dp[i+1][i][k+1], dp[i][j][k] + 1);
                    //変更しない
                    if(k > 0){
                        dp[i+1][j][k-1] = min(dp[i+1][j][k-1], dp[i][j][k]);
                    }

                }
            }
        }
    }

    int ans = INF;
    rep(i, len){
        ans = min(ans, dp[len][i][0] + i);
    }
    cout << ans << endl;

    return 0;
}
