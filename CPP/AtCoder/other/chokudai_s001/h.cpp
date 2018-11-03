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

    vector<int> dp(n+1, INF);
    dp[1] = a[0];
    for(int i = 1; i < n; i++){
        int lo = 0;
        int hi = n;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(dp[mid] < a[i]){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        dp[lo+1] = a[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] != INF){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
