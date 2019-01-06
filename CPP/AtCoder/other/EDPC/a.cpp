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

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;
    rep(i, n-1){
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if(i + 2 < n){
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}
