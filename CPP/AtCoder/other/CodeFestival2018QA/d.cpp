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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, f, t, n;
    cin >> d >> f >> t >> n;
    n += 2;
    vector<int> x(n);
    rep(i, n - 2) cin >> x[i+1];
    x[n-1] = d;

    vector<int> dp(n + 1), sum(n + 1);
    int lo = -1;
    int hi = n - 1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(x[mid] > f - t){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    dp[1] = powM(2, hi - 1);
    for(int i = 1; i < n - 1; i++){
        int begin, end;
        int lo = -1;
        int hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(x[mid] >= x[i] - f){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        begin = hi;

        lo = -1;
        hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(x[mid] >= x[i] - f + t){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        end = hi;

        dp[i+1] = (MOD + dp[end] - dp[begin]) % MOD;

        lo = -1;
        hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(x[mid] > x[i] + f - t){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        dp[i+1] *= powM(2, hi - i - 1);
        dp[i+1] %= MOD;

        dp[i+1] += dp[i];
        dp[i+1] %= MOD;
    }
    int ans;
    rep(i, n + 1){
        if(x[i] >= d - f){
            ans = MOD + dp[n-1] - dp[i];
            ans %= MOD;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
