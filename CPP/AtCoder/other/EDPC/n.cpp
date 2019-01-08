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
    vector<int> a(n+1);
    rep(i, n){
        cin >> a[i+1];
        a[i+1] += a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    rep(i, n){
        dp[i][i+1] = 0;
    }
    for(int l = 2; l <= n; l++){
        rep(i, n){
            if(i + l > n){
                break;
            }
            int k = min(n, i + l);
            for(int j = i; j <= k; j++){
                dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k] + a[k] - a[i]);
            }
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}
