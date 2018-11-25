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
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    rep(i, n) cin >> x[i];

    sort(ALL(x));
    vector<int> y(n);
    rep(i, n - 1){
        y[i] = x[i+1] - x[i];
    }

    int ans = 0;
    int sum = 0;
    for(int i = n-1; i >= 0; i--){
        sum = sum + y[i] * (n - 1 - i);
        ans += sum;
    }
    cout << ans << endl;

    return 0;
}
