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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int d;
    string n;
    cin >> d >> n;

    vector<vector<vector<int>>> dp((int)n.length() + 1, vector<vector<int>>(d, vector<int>(2)));
    dp[0][0][1] = 1;
    rep(i, (int)n.length()){
        rep(j, d){
            rep(k, 2){
                if(dp[i][j][k] == 0){
                    continue;
                }

                rep(x, 10){
                    if(k == 1 && x == (n[i] - '0')){
                        dp[i+1][(j+x)%d][1] = (dp[i+1][(j+x)%d][1] + dp[i][j][k]) % MOD;
                        break;
                    }
                    dp[i+1][(j+x)%d][0] = (dp[i+1][(j+x)%d][0] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    cout << dp[(int)n.length()][0][0] + dp[(int)n.length()][0][1] - 1 << endl;

    return 0;
}
