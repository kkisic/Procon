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
const int BIAS = 500;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dpL(n, INF), dpR(n, INF);
    dpL[0] = 0;

    rep(i, n - 1){
        dpL[i+1] = min(dpL[i], dpR[i]) + p;
        dpL[i+1] = min(dpL[i+1], dpL[i] + max(0LL, h[i+1] - h[i]));
        dpR[i+1] = min(dpL[i], dpR[i]) + p;
        dpR[i+1] = min(dpR[i+1], dpR[i] + max(0LL, h[i] - h[i+1]));
    }
    cout << min(dpL[n-1], dpR[n-1]) << endl;

    return 0;
}
