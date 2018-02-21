#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    sort(a.begin(), a.end());

    int ans = 0;
    for(int i = n-1; i >= 0; i -= 2){
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}
