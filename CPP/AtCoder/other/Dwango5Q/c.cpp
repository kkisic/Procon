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

    int n, q;
    string s;
    cin >> n >> s >> q;

    vector<int> k(q);
    rep(i, q) cin >> k[i];

    string d = "DMC";
    vector<vector<int>> dp(4, vector<int>(n+1));
    vector<int> m(n+1);
    dp[0][0] = 1;

    rep(i, n){
        rep(j, 4){
            dp[j][i+1] += dp[j][i];
            if(j < 3 && s[i] == d[j]){
                dp[j+1][i+1] += dp[j][i+1];
            }
        }
        m[i+1] = m[i] + (s[i] == d[1]);
    }

    rep(i, q){
        int ans = 0;

        rep(j, n){
            if(s[j] != 'C'){
                continue;
            }
            int l = max(0LL, j - k[i] + 1);
            int cnt = m[j] - m[l];
            int tmp = dp[2][j] - dp[2][l];
            tmp -= dp[1][l] * cnt;
            ans += tmp;
        }
        cout << ans << endl;
    }

    return 0;
}
