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

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int ans = 0;
    rep(i, n){
        if((k | a[i]) == k){
            ans += b[i];
        }
    }

    rep(i, 30){
        if((k >> i) == 0){
            break;
        }
        if((k >> i) % 2 == 0){
            continue;
        }

        int tmp = 0;
        int limit = (1LL << (i)) - 1;
        limit |= k;
        limit ^= 1LL << (i);
        rep(i, n){
            if((limit | a[i]) == limit){
                tmp += b[i];
            }
        }
        if(tmp > ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
