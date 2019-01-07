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
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector<int> sum(1 << n);
    rep(i, n){
        rep(s, 1 << i){
            sum[s|(1<<i)] = sum[s];
            rep(j, i){
                if((s >> j) % 2 == 0){
                    continue;
                }
                sum[s|(1<<i)] += a[i][j];
            }
        }
    }

    vector<int> dp(1 << n);
    rep(s, 1 << n){
        for(int t = s; t != 0; t = (t - 1) & s){
            dp[s] = max(dp[s], dp[s^t] + sum[t]);
        }
    }
    cout << dp[(1<<n)-1] << endl;

    return 0;
}
