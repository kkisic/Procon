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

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> k(3);
    rep(i, 3){
        k[i] = r / 3 - (l - 1) / 3;
        if(i > r % 3){
            k[i]--;
        }
        if(i > (l - 1) % 3){
            k[i]++;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[0][0] = 1;
    rep(i, n){
        rep(j, 3){
            rep(l, 3){
                dp[i+1][l] += dp[i][j] * k[(3+l-j)%3] % MOD;
                dp[i+1][l] %= MOD;
            }
        }
    }
    cout << dp[n][0] << endl;

    return 0;
}
