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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    s[0] = 0;
    for(int i = 0; i < n; i++){
        s[i+1] = s[i] + a[i];
    }

    int ans = INF;
    for(int q = 2; q <= n-2; q++){
        int l = 0;
        int r = q;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(s[q] / 2 > s[m]){
                l = m;
            }else{
                r = m;
            }
        }
        int p = l;
        if(p == 0){
            p++;
        }

        l = q;
        r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            if((s[n] - s[q]) / 2 > s[m] - s[q]){
                l = m;
            }else{
                r = m;
            }
        }
        int t = l;
        if(t == q){
            t++;
        }

        vector<int> x1 = {s[p], s[q]-s[p], s[t]-s[q], s[n]-s[t]};
        int tmp;
        tmp = abs(*max_element(x1.begin(), x1.end()) - *min_element(x1.begin(), x1.end()));
        if(tmp < ans){
            ans = tmp;
        }

        if(p + 1 < q){
            vector<int> x2 = {s[p+1], s[q]-s[p+1], s[t]-s[q], s[n]-s[t]};
            tmp = abs(*max_element(x2.begin(), x2.end()) - *min_element(x2.begin(), x2.end()));
            if(tmp < ans){
                ans = tmp;
            }
        }
        if(t + 1 < n){
            vector<int> x3 = {s[p], s[q]-s[p], s[t+1]-s[q], s[n]-s[t+1]};
            tmp = abs(*max_element(x3.begin(), x3.end()) - *min_element(x3.begin(), x3.end()));
            if(tmp < ans){
                ans = tmp;
            }
        }
        if(p + 1 < q && t + 1 < n){
            vector<int> x4 = {s[p+1], s[q]-s[p+1], s[t+1]-s[q], s[n]-s[t+1]};
            tmp = abs(*max_element(x4.begin(), x4.end()) - *min_element(x4.begin(), x4.end()));
            if(tmp < ans){
                ans = tmp;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
