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
    int v0, v1, v2, v3;
    cin >> v0 >> v1 >> v2 >> v3;

    int ans = INF;
    for(int a = 1; a <= 30; a++){
        for(int b = 1; b <= 30; b++){
            for(int c = 1; c <= 30; c++){
                vector<int> x = {a, b, c};
                vector<int> dp(31, INF);
                dp[0] = 0;

                rep(i, 3){
                    for(int j = 1; j <= 30; j++){
                        if(j < x[i] || dp[j-x[i]] == INF){
                            continue;
                        }
                        dp[j] = min(dp[j], dp[j-x[i]] + 1);
                    }
                }
                int tmp = dp[v0] + dp[v1] + dp[v2] + dp[v3];
                if(ans > tmp){
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
