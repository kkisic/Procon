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
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i, m) cin >> c[i];

    vector<int> dp(n+1, INF);
    dp[0] = 0;
    rep(i, m){
        rep(j, n+1){
            if(j < c[i] || dp[j-c[i]] == INF){
                continue;
            }
            dp[j] = min(dp[j], dp[j-c[i]] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
