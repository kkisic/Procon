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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;
    int maxi = 0;
    rep(i, n){
        sum += a[i];
        maxi = max(maxi, a[i]);
    }

    int ans = maxi;
    while(ans * n - sum <= sum){
        ans++;
    }
    cout << ans << endl;

    return 0;
}
