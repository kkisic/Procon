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

    int ans = 0;
    for(int x = sqrt(m); x >= 1; x--){
        if(m % x == 0){
            if(x >= n){
                ans = max(ans, m / x);
            }
            if(m / x >= n){
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
