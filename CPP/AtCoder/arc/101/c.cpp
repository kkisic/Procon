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
    vector<int> x, y;
    rep(i, n){
        int a;
        cin >> a;
        if(a < 0){
            y.push_back(abs(a));
        }else{
            x.push_back(a);
        }
    }
    if(y.size() > 0){
        sort(y.begin(), y.end());
    }


    int ans = INF;
    if(y.size() >= k && ans > y[k-1]){
        ans = y[k-1];
    }
    if(x.size() >= k && ans > x[k-1]){
        ans = x[k-1];
    }

    for(int i = 1; i < k-1; i++){
        if(x.size() < i+1 || y.size() < k-1-i){
            continue;
        }

        int mi = min(x[i], y[k-2-i]);
        int ma = max(x[i], y[k-2-i]);

        if(mi * 2 + ma < ans){
            ans = mi * 2 + ma;
        }
    }
    cout << ans << endl;

    return 0;
}
