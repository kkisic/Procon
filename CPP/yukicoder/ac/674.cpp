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

const int INF = 1e18;
const int MOD = 1e9+7;

signed main(){
    int d, q;
    cin >> d >> q;

    set<P> range;
    range.emplace(-INF-10, -INF-10);
    range.emplace(INF+10, INF+10);
    int ans = 0;
    rep(i, q){
        int a, b;
        cin >> a >> b;
        P r = make_pair(a, b);
        auto x_ = range.lower_bound(r);
        x_--;
        P x = *x_;

        if(x.second + 1 >= r.first){
            r.first = x.first;
            r.second = max(r.second, x.second);
            range.erase(x);
        }

        auto y_ = range.upper_bound(r);
        P y = *y_;
        while(y.first <= r.second + 1){
            r.second = max(r.second, y.second);
            y_ = range.erase(y_);
            y = *y_;
        }
        range.insert(r);

        int len = r.second - r.first + 1;
        if(ans < len){
            ans = len;
        }
        cout << ans << endl;
    }
    return 0;
}
