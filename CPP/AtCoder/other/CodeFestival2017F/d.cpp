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

bool compare(P a, P b){
    return a.first + a.second < b.first + b.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> v(n);
    rep(i, n){
        int h, p;
        cin >> h >> p;
        v[i] = {h, p};
    }
    sort(ALL(v), compare);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    rep(i, n){
        for(int j = 0; j <= i; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(dp[i][j] > v[i].first){
                continue;
            }
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + v[i].second);
        }
    }

    int ans = 0;
    rep(i, n + 1){
        if(dp[n][i] != INF){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
