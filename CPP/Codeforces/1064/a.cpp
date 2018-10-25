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
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.begin(), a.end());

    cout << max(a[2] + 1 - a[0] - a[1], 0LL) << endl;

    return 0;
}
