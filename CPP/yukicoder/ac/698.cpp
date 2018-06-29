#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(1 << n);
    dp[0] = 0;
    rep(s, (1 << n)){
        vector<int> x;

        rep(i, n){
            if((s >> i) % 2 == 1){
                x.push_back(i);
            }
        }
        if(x.size() % 2 == 1){
            continue;
        }

        rep(i, (int)x.size()){
            for(int j = i+1; j < (int)x.size(); j++){
                int ss = s ^ (1 << x[i]) ^ (1 << x[j]);

                dp[s] = max(dp[s], dp[ss] + (a[x[i]] ^ a[x[j]]));
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}
