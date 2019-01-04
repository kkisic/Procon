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
    sort(ALL(a), greater<int>());

    int sum = 0;
    rep(i, n) sum += a[i];

    if(sum % 360 == 0){
        cout << "YES" << endl;
        return 0;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(360, false));
    dp[0][0] = true;
    rep(i, n){
        rep(j, 360){
            if(not dp[i][j]){
                continue;
            }
            dp[i+1][(j+a[i])%360] = true;
            dp[i+1][(j+360-a[i])%360] = true;
        }
    }

    if(dp[n][0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
