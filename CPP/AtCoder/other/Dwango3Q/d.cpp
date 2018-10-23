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
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<int> ys(n+1);
    rep(i, n){
        ys[i+1] = ys[i] + y[i];
        x[i] -= y[i];
    }

    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> xs(n+1);
    int sum = 0;
    rep(i, n){
        sum += x[i];
        que.push(x[i]);
        if((int)que.size() >= m){
            sum -= que.top();
            que.pop();
        }
        xs[i+1] = sum;
    }

    int ans = 0;
    rep(i, n){
        ans = max(ans, xs[i] + ys[i+1] + x[i]);
    }
    cout << ans << endl;

    return 0;
}
