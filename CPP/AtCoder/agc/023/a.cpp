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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n);
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i-1] + a[i];
    }
    sort(s.begin(), s.end());
    int x = s[0];
    int c = 0;
    int ans = 0;

    rep(i, n){
        if(x == s[i]){
            c++;
        }else{
            if(x == 0){
                ans += c;
            }
            ans += c * (c - 1) / 2;
            x = s[i];
            c = 1;
        }
    }
    if(x == 0){
        ans += c;
    }
    ans += c * (c - 1) / 2;
    cout << ans << endl;

    return 0;
}
