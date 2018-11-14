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

    vector<int> x(n);
    rep(i, n){
        char c;
        cin >> c;
        x[i] = c - '0';
    }

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = s[i] + x[i];
    }

    vector<int> ss(n+1, 1);
    rep(i, n){
        ss[i+1] = ss[i] * 2 % MOD;
    }

    vector<int> sss(n+1);
    rep(i, n){
        sss[i+1] = sss[i] + ss[i] % MOD;
    }

    rep(i, q){
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int len = r - l + 1;
        int sum = s[r+1] - s[l];
        int ans = (MOD + sss[len] - sss[len - sum]) % MOD;
        cout << ans << endl;
    }

    return 0;
}
