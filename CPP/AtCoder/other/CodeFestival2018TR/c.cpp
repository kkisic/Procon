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

    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> p(n);
    rep(i, n) p[i] = i;

    int ans = 0;
    while(true){
        int sum = 0;
        int idx = 0;
        bool ok = true;
        bool s[10] = {};

        rep(i, n){
            while(idx < n && sum + a[idx] <= h){
                sum += a[idx];
                s[idx++] = true;
            }

            if(not s[p[i]]){
                ok = false;
                break;
            }
            sum -= a[p[i]];
            s[p[i]] = false;
        }

        if(ok){
            ans++;
        }

        if(not next_permutation(ALL(p))){
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
