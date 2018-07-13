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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<P> s;
    s.emplace_back(a[0], 1);
    int c = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == s[c-1].first){
            s[c-1].second++;
            continue;
        }
        s.emplace_back(a[i], 1);
        c++;
    }

    vector<int> dp(1e5);
    dp[0] = 1;
    int limit = 0;
    rep(i, c){
        vector<int> tmp(1e5);

        for(int j = 0; j <= limit; j++){
            if(dp[j] == 0){
                continue;
            }
            int t = powM(2, s[i].second-1);
            tmp[j] += dp[j] * t;
            tmp[j] %= MOD;
            tmp[j^s[i].first] += dp[j] * t;
            tmp[j^s[i].first] %= MOD;

        }
        limit |= s[i].first;
        swap(dp, tmp);
    }
    cout << dp[k] << endl;

    return 0;
}
