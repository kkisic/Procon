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
    int t;
    cin >> t;

    rep(i, t){
        int len, v, l, r;
        cin >> len >> v >> l >> r;

        int ans = len / v;
        int inv = r / v - (l - 1) / v;
        cout << ans - inv << endl;
    }

    return 0;
}
