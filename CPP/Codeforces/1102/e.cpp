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
const int MOD = 998244353;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> a(n);
    rep(i, n) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(ALL(a));

    vector<P> range;
    rep(i, n){
        if(range.empty() || a[i].first != a[i-1].first){
            range.emplace_back(a[i].second, a[i].second);
            continue;
        }
        range.back().second = a[i].second;
    }
    sort(ALL(range));

    int cnt = 0;
    int last = -1;
    rep(i, SZ(range)){
        if(last < range[i].first){
            cnt++;
            last = range[i].second;
            continue;
        }
        last = max(last, range[i].second);
    }

    int ans = 1;
    rep(i, cnt - 1){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
