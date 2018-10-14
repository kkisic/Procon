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
    int n, x;
    cin >> n >> x;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int maxi = 0;
    rep(i, n){
        maxi = max(maxi, b[i]);
    }

    bool used = false;
    int ans = 0;
    rep(i, n){
        if(b[i] == maxi && not used){
            ans += b[i] * (a[i] + x);
            used = true;
            continue;
        }
        ans += a[i] * b[i];
    }
    cout << ans << endl;
    return 0;
}
