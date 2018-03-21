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

int solve(vector<int> a, vector<int> b, int k){
    int t = 1 << k;
    int m = 1 << (k+1) ;
    int n = a.size();
    rep(i, n){
        a[i] %= m;
        b[i] %= m;
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    int ans = 0;
    int it1, it2, it3, it4;
    it1 = it2 = it3 = it4 = 0;

    rep(i, n){
        while(b[it1] < t - a[i]     && it1 < n) it1++;
        while(b[it2] < 2 * t - a[i] && it2 < n) it2++;
        while(b[it3] < 3 * t - a[i] && it3 < n) it3++;
        while(b[it4] < 4 * t - a[i] && it4 < n) it4++;
        ans += it4 - it3 + it2 - it1;
    }

    return ans;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = 0;

    rep(i, 30){
        int s = solve(a, b, i);
        if(s % 2 == 1){
            ans |= 1 << i;
        }
    }
    cout << ans << endl;

    return 0;
}
