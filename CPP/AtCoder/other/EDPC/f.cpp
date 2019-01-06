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

    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(SZ(s) + 1, vector<int>(SZ(t) + 1));
    rep(i, SZ(s) + 1){
        rep(j, SZ(t) + 1){
            if(i + 1 <= SZ(s)){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
            if(j + 1 <= SZ(t)){
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
            if(i + 1 <= SZ(s) && j + 1 <= SZ(t)){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (s[i] == t[j]));
            }
        }
    }

    int x = SZ(s);
    int y = SZ(t);
    string ans;
    while(x > 0 && y > 0){
        if(s[x-1] == t[y-1]){
            ans.push_back(s[x-1]);
            x--;
            y--;
            continue;
        }
        if(dp[x][y] == dp[x-1][y]){
            x--;
            continue;
        }
        y--;
    }
    reverse(ALL(ans));
    cout << ans << endl;

    return 0;
}
