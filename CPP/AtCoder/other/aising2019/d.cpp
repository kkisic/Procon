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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n + 1);
    rep(i, n) s[i+1] = s[i] + a[i];
    vector<int> ss((n + 1) / 2 + 1);
    int x = (n + 1) % 2;
    rep(i, (n + 1) / 2){
        ss[i+1] = ss[i] + a[x+2*i];
    }

    vector<P> query(q);
    rep(i, q){
        int x;
        cin >> x;
        query[i] = {x, i};
    }
    sort(ALL(query));

    vector<int> ans(q);
    int y = 1;
    rep(i, q){
        int x = query[i].first;

        while(y < n && a[y-1] < x){
            y++;
        }

        while(y < n){
            int limit = max(1LL, 2 * x - a[y-1]);
            int lo = -1;
            int hi = n - 1;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(a[mid] >= limit){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }
            int upper = n - y + 1;
            int lower = y - hi;
            if(upper > lower){
                y++;
            }else{
                break;
            }
        }
        int result = s[n] - s[y-1];
        int remain = n - (n - y + 1) * 2;
        if(remain > 0){
            result += ss[(remain+1)/2];
        }
       ans[query[i].second] = result;
    }

    rep(i, q){
        cout << ans[i] << endl;
    }

    return 0;
}
