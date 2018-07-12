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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = a[i] + s[i];
    }

    rep(i, q){
        int c, d;
        cin >> c >> d;

        int lo, hi;
        lo = -1;
        hi = n;
        while(hi - lo > 1){
            int m = (hi + lo) / 2;
            if(a[m] < c - d){
                lo = m;
            }else{
                hi = m;
            }
        }
        int x = lo;

        lo = -1;
        hi = n;
        while(hi - lo > 1){
            int m = (hi + lo) / 2;
            if(a[m] <= c){
                lo = m;
            }else{
                hi = m;
            }
        }
        int y = lo;

        lo = -1;
        hi = n;
        while(hi - lo > 1){
            int m = (hi + lo) / 2;
            if(a[m] <= c + d){
                lo = m;
            }else{
                hi = m;
            }
        }
        int z = lo;

        int ans = 0;
        ans += c * (y - x) - (s[y+1] - s[x+1]);
        ans += s[z+1] - s[y+1] - c * (z - y);
        ans += d * x;
        ans += d * (n - z);

        cout << ans << endl;
    }

    return 0;
}
