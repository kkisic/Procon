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

    int n, m, l, x;
    cin >> n >> m >> l >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(m, INF);
    dp[0] = 0;
    rep(i, n){
        vector<int> tmp(m, INF);
        rep(j, m){
            tmp[j] = min(tmp[j], dp[j]);
            int nxt = (j + a[i]) % m;
            int sum = j + 1 + a[i] - m;
            int c = sum / m;
            c += dp[j];
            if(sum % m != 0){
                c++;
            }
            tmp[nxt] = min(tmp[nxt], c);
        }
        dp = tmp;
    }

    if(dp[l] < x){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
