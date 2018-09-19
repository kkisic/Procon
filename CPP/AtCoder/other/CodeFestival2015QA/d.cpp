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

int n, m;

bool check(const vector<int>& x, int t){
    int next = 1;
    rep(i, m){
        if(next > n){
            return true;
        }
        if(x[i] - t > next){
            return false;
        }
        if(next >= x[i]){
            next = x[i] + t + 1;
            continue;
        }
        int dist = x[i] - next;
        next = x[i] + max(t - dist * 2, (t - dist) / 2) + 1;
    }

    return next > n;
}

signed main(){
    cin >> n >> m;

    if(n == m){
        cout << 0 << endl;
        return 0;
    }

    vector<int> x(m);
    rep(i, m) cin >> x[i];

    int lo = 0;
    int hi = n * 2;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(check(x, mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi << endl;

    return 0;
}
