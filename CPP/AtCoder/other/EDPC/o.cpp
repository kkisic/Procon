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

    vector<int> dp(1 << n);
    dp[0] = 1;
    rep(s, 1 << n){
        int x = 0;
        rep(i, n){
            if((s >> i) % 2){
                x++;
            }
        }
        rep(i, n){
            if((s >> i) % 2){
                continue;
            }
            if(a[x][i] == 0){
                continue;
            }
            dp[s|(1<<i)] += dp[s];
            dp[s|(1<<i)] %= MOD;
        }
    }
    cout << dp[(1<<n)-1] << endl;

    return 0;
}
