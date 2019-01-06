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

    int h, w;
    cin >> h >> w;
    vector<vector<bool>> a(h, vector<bool>(w, true));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == '#'){
                a[i][j] = false;
            }
        }
    }

    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;
    rep(i, h){
        rep(j, w){
            if(not a[i][j]){
                continue;
            }
            if(i + 1 < h && a[i+1][j]){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            if(j + 1 < w && a[i][j+1]){
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;

    return 0;
}
