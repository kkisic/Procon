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
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum, item;
    int ans = 0;
    bool ok = true;
    while(ok && t > 0){
        ok = false;

        sum = item = 0;
        for(int i = 0; i < n; i++){
            if(sum + a[i] <= t){
                sum += a[i];
                item++;
            }
        }

        if(sum == 0){
            break;
        }

        int x = t / sum;
        ans += x * item;
        t -= x * sum;
        if(x > 0){
            ok = true;
        }
    }
    cout << ans << endl;

    return 0;
}
