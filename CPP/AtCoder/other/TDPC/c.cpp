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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

double p(int a, int b){
    return 1.0 / (1.0 + pow(10.0, (b - a) / 400.0));
}

signed main(){
    int k;
    cin >> k;

    vector<int> r(1 << k);
    rep(i, (1 << k)) cin >> r[i];

    vector<vector<double>> dp(k+1, vector<double>(1 << k));
    rep(i, (1 << k)){
        dp[0][i] = 1.0;
    }

    rep(i, k){
        rep(j, (1 << k)){
            int s = (j ^ (1 << i)) & (~((1 << i) - 1));
            rep(l, (1 << i)){
                dp[i+1][j] += dp[i][j] * dp[i][s|l] * p(r[j], r[s|l]);
            }
        }
    }

    rep(i, (1 << k)){
        cout << fixed << setprecision(9) << dp[k][i] << endl;
    }

    return 0;
}
