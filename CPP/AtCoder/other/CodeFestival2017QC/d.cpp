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

signed dp[1<<26];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = SZ(s);
    vector<int> a(n + 1);

    rep(i, n){
        a[i+1] = a[i] ^ (1 << (s[i] - 'a'));
    }

    rep(i, 1 << 26){
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(__builtin_popcount(a[i]) <= 1){
            dp[a[i]] = 1;
        }
        rep(j, 26){
            int x = (1 << j) ^ a[i];
            dp[a[i]] = min(dp[a[i]], dp[x] + 1);
        }
    }
    cout << dp[a[n]] << endl;

    return 0;
}
