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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    map<int, int> m;
    vector<int> left(n+1, INF);
    left[0] = 0;
    m[0] = 1;
    for(int i = 1; i <= n; i++){
        if(m.find(s[i]) == m.end()){
            m[s[i]] = 0;
        }

        left[i] = left[i-1] + m[s[i]];
        m[s[i]]++;
    }

    m = map<int, int>();
    vector<int> right(n+2, INF);
    right[n+1] = 0;
    for(int i = n; i >= 1; i--){
        if(m.find(s[i]) == m.end()){
            m[s[i]] = 1;
            right[i] = right[i+1];
            continue;
        }
        right[i] = right[i+1] + m[s[i]];
        m[s[i]]++;
    }

    int ans = INF;
    for(int i = 1; i <= n; i++){
        if(ans > left[i-1] + right[i]){
            ans = left[i-1] + right[i];
        }
    }

    cout << ans << endl;

    return 0;
}
