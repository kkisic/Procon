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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> x(n+1, b);
    rep(i, m){
        int l, r;
        cin >> l >> r;
        for(int j = l; j <= r; j++){
            x[j] = a;
        }
    }

    int ans = 0;
    rep(i, n){
        ans += x[i+1];
    }
    cout << ans << endl;

    return 0;
}
