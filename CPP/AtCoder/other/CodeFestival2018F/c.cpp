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

    int n;
    cin >> n;

    vector<P> cost(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        cost[i] = {a, b};
    }
    sort(ALL(cost));

    int m;
    cin >> m;
    rep(i, m){
        int t;
        cin >> t;

        int lo = -1;
        int hi = n-1;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;

            if(cost[mid].first >= t){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        if(hi == 0){
            cout << cost[hi].second << endl;
            continue;
        }

        int tmp1 = cost[hi-1].second + t - cost[hi-1].first;
        int tmp2 = cost[hi].second;
        if(t > cost[hi].first){
            tmp2 = cost[hi].second + t - cost[hi].first;
        }
        cout << min(tmp1, tmp2) << endl;
    }

    return 0;
}
