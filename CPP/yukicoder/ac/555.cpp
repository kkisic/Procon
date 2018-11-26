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

    int n, c, v;
    cin >> n >> c >> v;

    vector<int> dp(n+1, INF);
    dp[1] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 2; i * j < n * 2; j++){
            int nxt = min(i * j, n);
            dp[nxt] = min(dp[nxt], dp[i] + c + v * (j - 1));
        }
    }
    cout << dp[n] << endl;

    return 0;
}
