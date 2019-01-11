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

struct block{
    int w, s, v;
};

bool compare(block a, block b){
    return a.w + a.s < b.w + b.s;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<block> vb(n);
    rep(i, n){
        int w, s, v;
        cin >> w >> s >> v;
        vb[i] = {w, s, v};
    }
    sort(ALL(vb), compare);

    vector<vector<int>> dp(n + 1, vector<int>(20001));
    rep(i, n){
        rep(j, 20000){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j > vb[i].s){
                continue;
            }
            if(j + vb[i].w > 20000){
                continue;
            }
            dp[i+1][j+vb[i].w] = max(dp[i+1][j+vb[i].w], dp[i][j] + vb[i].v);
        }
    }

    int ans = 0;
    rep(i, 20001){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
