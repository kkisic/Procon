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
    int n, k;
    cin >> n >> k;
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        pq.emplace(a, b);
    }

    int ans = 0;
    rep(i, k){
        P p = pq.top();
        pq.pop();
        ans += p.first;
        pq.emplace(p.first + p.second, p.second);
    }
    cout << ans << endl;


    return 0;
}
