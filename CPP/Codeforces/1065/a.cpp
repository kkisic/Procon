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
    int n;
    cin >> n;

    rep(i, n){
        int s, a, b, c;
        cin >> s >> a >> b >> c;

        int ans = s / (a * c) * (a + b);
        int re = s % (a * c);
        ans += re / c;
        cout << ans << endl;
    }

    return 0;
}
