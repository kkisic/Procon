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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(n+1);
    dp[0] = 1;
    rep(i, n){
        deque<int> div;
        for(int j = round(sqrt(a[i])); j > 0; j--){
            if(a[i] % j != 0){
                continue;
            }
            div.push_back(j);
            if(j * j == a[i]){
                continue;
            }
            div.push_front(a[i]/j);
        }

        rep(j, SZ(div)){
            if(div[j] > i + 1){
                continue;
            }
            dp[div[j]] = (dp[div[j]] + dp[div[j]-1]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
