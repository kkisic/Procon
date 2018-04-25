#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

    vector<int> l(n*2);
    rep(i, n*2) cin >> l[i];
    sort(l.begin(), l.end());

    int ans = 0;
    for(int i = 0; i < n * 2; i += 2){
        ans += l[i];
    }
    cout << ans << endl;

    return 0;
}
