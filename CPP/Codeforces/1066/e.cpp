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
const int MOD = 998244353;

signed main(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    vector<int> s(n);
    s[n-1] = 1;
    for(int i = n-1; i > 0; i--){
        s[i-1] = s[i] * 2 % MOD;
    }

    int ans = 0;
    int cnt = 0;
    int j = max(0LL, n - m);
    rep(i, m){
        if(b[i] == '1'){
            cnt++;
        }
        if(m - i > n){
            continue;
        }
        if(a[j] == '1'){
            ans = (ans + s[j] * cnt % MOD) % MOD;
        }
        j++;
    }
    cout << ans << endl;

    return 0;
}
