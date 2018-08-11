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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    s[0] = 0;
    rep(i, n){
        s[i+1] = (s[i] + a[i]) % m;
    }

    map<int, int> mp;
    rep(i, n){
        if(mp.find(s[i+1]) == mp.end()){
            mp.emplace(s[i+1], 0);
        }
        mp[s[i+1]]++;
    }

    int ans = 0;
    for(P p : mp){
        if(p.first == 0){
            ans += p.second;
        }
        ans += (p.second - 1) * p.second / 2;
    }
    cout << ans << endl;

    return 0;
}
