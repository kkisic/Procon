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

const int INF = 1e17;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<int> x(n), c(n), v(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> v[i];

    vector<int> xs(n+1);
    rep(i, n){
        xs[i+1] = xs[i] + x[i];
    }

    vector<int> cs(1 << n), vs(1 << n);
    rep(s, (1 << n)){
        rep(i, n){
            if((s >> i) % 2 == 1){
                continue;
            }
            cs[s ^ (1 << i)] = cs[s] + c[i];
            vs[s ^ (1 << i)] = vs[s] + v[i];
        }
    }

    vector<vector<int>> k(n+1, vector<int>(1 << n));
    rep(i, n+1){
        rep(s, (1 << n)){
            if(xs[i] >= cs[s]){
                k[i][s] = vs[s];
                continue;
            }

            int tmp = 0;
            rep(j, n){
                if((s >> j) % 2 == 0){
                    continue;
                }
                tmp = max(tmp, k[i][s^(1<<j)]);
            }
            k[i][s] = tmp;
        }
    }

    vector<int> dp(1 << n);
    //0買えない 1買える
    for(int s = 1; s < (1 << n); s++){
        int tmp = INF;
        rep(i, n){
            if((s >> i) % 2 == 0){
                continue;
            }

            tmp = min(tmp, dp[s ^ (1 << i)]);
        }
        int sold = n - bitset<18>(s).count();
        dp[s] = max(tmp, k[sold][s]);
    }
    cout << dp[(1 << n) - 1] << endl;

    int ans = 0;
    rep(i, (1 << n)){
        ans = max(ans, dp[i]);
    }

    return 0;
}
