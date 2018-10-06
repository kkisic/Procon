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

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, l, a;
    cin >> n >> l >> a;

    vector<int> t(n+1), ll(n+1);
    rep(i, n) cin >> t[i] >> ll[i];
    t[n] = l;

    int ans = t[0] / a;
    rep(i, n){
        int x = t[i+1] - (t[i] + ll[i]);
        ans += x / a;
    }
    cout << ans << endl;

    return 0;
}
