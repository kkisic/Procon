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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    multiset<int> up, down;
    rep(i, k){
        down.insert(INF);
    }
    rep(i, n){
        int t, a;
        cin >> t >> a;

        ans += a;
        if(t){
            up.insert(a);
            if(not down.empty()){
                auto it = down.end();
                it--;
                down.erase(it);
            }else{
                ans -= *(up.begin());
                up.erase(up.begin());
            }
        }else{
            down.insert(a);
            if(not up.empty()){
                auto it = up.end();
                it--;
                up.erase(it);
            }else{
                ans -= *(down.begin());
                down.erase(down.begin());
            }
        }
    }
    cout << ans << endl;

    return 0;
}
