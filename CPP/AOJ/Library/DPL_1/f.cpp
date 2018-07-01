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
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    rep(i, N) cin >> v[i] >> w[i];

    vector<int> dp(10001, INF);
    dp[0] = 0;
    rep(i, N){
        for(int j = 10000; j >= 0; j--){
            if(j < v[i] || dp[j - v[i]] == INF){
                continue;
            }
            dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
        }
    }

    int ans = 0;
    rep(i, 10001){
        if(dp[i] <= W){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
