#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edge(m);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = make_tuple(a, b, c);
    }
    vector<int> d(k+1);
    rep(i, k) cin >> d[i+1];

    vector<vector<bool>> dp(k+1, vector<bool>(n+1, false));
    rep(i, n){
        dp[0][i+1] = true;
    }
    for(int i = 1; i <= k; i++){
        rep(j, m){
            if(get<2>(edge[j]) != d[i]){
                continue;
            }
            int p = get<0>(edge[j]);
            int q = get<1>(edge[j]);
            if(dp[i-1][p]){
                dp[i][q] = true;
            }
            if(dp[i-1][q]){
                dp[i][p] = true;
            }
        }
    }
    int ans = 0;
    vector<int> ansV;
    rep(i, n){
        if(dp[k][i+1]){
            ans++;
            ansV.push_back(i+1);
        }
    }
    cout << ans << endl;
    rep(i, (int)ansV.size()-1){
        cout << ansV[i] << " ";
    }
    cout << ansV[(int)ansV.size()-1] << endl;

    return 0;
}
