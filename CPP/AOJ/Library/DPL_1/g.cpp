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
    vector<int> v(N), w(N), m(N);
    rep(i, N) cin >> v[i] >> w[i] >> m[i];

    vector<int> vv, ww;
    rep(i, N){
        for(int j = 0; j <= 13; j++){
            int x = pow(2, j);
            if(x > m[i]){
                break;
            }
            vv.push_back(v[i] * x);
            ww.push_back(w[i] * x);
            m[i] -= x;
        }
        for(int j = 13; j >= 0; j--){
            int x = pow(2, j);
            if(x > m[i]){
                continue;
            }
            vv.push_back(v[i] * x);
            ww.push_back(w[i] * x);
            m[i] -= x;
        }
    }

    int nn = vv.size();
    vector<int> dp(W+1, 0);
    rep(i, nn){
        vector<int> tmp(W+1);
        for(int j = W; j >= 0; j--){
            if(j < ww[i] || dp[j-ww[i]] == -1){
                tmp[j] = dp[j];
                continue;
            }
            tmp[j] = max(dp[j], dp[j-ww[i]] + vv[i]);
        }
        swap(dp, tmp);
    }

    int ans = 0;
    rep(i, W+1){
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    cout << ans << endl;

    return 0;
}
