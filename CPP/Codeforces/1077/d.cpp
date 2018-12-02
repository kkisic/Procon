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
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    vector<int> a(2e5+1, 0);
    rep(i, n){
        a[s[i]]++;
    }

    int lo = 0;
    int hi = n + 1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;

        int cnt = 0;
        rep(i, 2e5+1){
            cnt += a[i] / mid;
        }
        if(cnt >= k){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    vector<int> ans;
    int m = k;
    rep(i, 2e5+1){
        while(a[i] >= lo && m > 0){
            ans.push_back(i);
            a[i] -= lo;
            m--;
        }
    }

    cout << ans[0];
    for(int i = 1; i < k; i++){
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
