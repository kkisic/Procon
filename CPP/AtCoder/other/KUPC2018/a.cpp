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
    vector<int> s(n), a(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> a[i];

    int ans = 0;
    rep(i, n){
        if(ans < s[i] * a[i]){
            ans = s[i] * a[i];
        }
    }
    cout << ans << endl;

    return 0;
}
