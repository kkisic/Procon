#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n;
    cin >> n;

    vector<int> t(n), a(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];

    if(t[n-1] != a[0]){
        cout << 0 << endl;
        return 0;
    }

    vector<int> h(n, -1);
    h[0] = t[0];
    for(int i = 1; i < n; i++){
        if(t[i] > t[i-1]){
            h[i] = t[i];
        }
    }

    if(h[n-1] != -1 && h[n-1] != a[n-1]){
        cout << 0 << endl;
        return 0;
    }

    h[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        if(a[i] > a[i+1]){
            if(t[i] < a[i]){
                cout << 0 << endl;
                return 0;
            }
            if(h[i] != -1 && h[i] != a[i]){
                cout << 0 << endl;
                return 0;
            }
            h[i] = a[i];
        }
    }

    int ans = 1;
    int x = h[0];
    int cnt = 0;
    rep(i, n){
        if(h[i] != -1){
            int p = min(x, h[i]);
            rep(j, cnt){
                ans = ans * p % MOD;
            }
            x = h[i];
            cnt = 0;
        }else{
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
