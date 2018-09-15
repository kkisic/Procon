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
    n = 1000 - n;

    int ans = 0;
    vector<int> a = {500, 100, 50, 10, 5, 1};
    rep(i, 6){
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans << endl;

    return 0;
}
