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

bool able(char a, char b, char c){
    return (a == 'i' && b == 'w' && c == 'i');
}

signed main(){
    string s;
    cin >> s;

    int n = s.length();
    vector<vector<bool>> take(n, vector<bool>(n, false));

    for(int d = 2; d < n; d += 3){
        rep(i, n){
            int j = i + d;
            if(j >= n){
                continue;
            }

            if(d == 2){
                if(able(s[i], s[i+1], s[i+2])){
                    take[i][j] = true;
                }
                continue;
            }

            for(int s = i + 1; s + 1 < j; s++){
                if(take[i][s] && take[s+1][j]){
                    take[i][j] = true;
                    break;
                }
            }

            if(take[i+1][j-2] && able(s[i], s[j-1], s[j])){
                take[i][j] = true;
            }

            if(take[i+2][j-1] && able(s[i], s[i+1], s[j])){
                take[i][j] = true;
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            if(take[i][j]){
                dp[i][j] = j - i + 1;
            }
        }
    }

    rep(i, n){
        for(int j = i + 1; j < n; j++){
            for(int k = i; k < j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1] / 3 << endl;

    return 0;
}
