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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    set<int> c;
    rep(i, n){
        if(c.find(a[i]) != c.end()){
            cout << 0 << endl;
            return 0;
        }
        c.insert(a[i]);
    }
    c = set<int>();
    rep(i, m){
        if(c.find(b[i]) != c.end()){
            cout << 0 << endl;
            return 0;
        }
        c.insert(b[i]);
    }

    vector<int> s(n * m + 1);
    vector<bool> t(n * m + 1, false), u(n * m + 1, false);
    rep(i, n){
        rep(j, m){
            int x = min(a[i], b[j]);
            s[x]++;
            u[x] = true;
            if(a[i] == b[j]){
                t[x] = true;
            }
        }
    }

    if(s[n*m] == 0){
        cout << 0 << endl;
        return 0;
    }

    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());
    int tar = n * m;
    rep(i, n){
        rep(j, m){
            if(a[i] == b[j]){
                tar = min(tar, a[i] - 1);
                while(tar > 1 && u[tar]){
                    tar--;
                }
                s[tar] += s[a[i]] - 1;
                s[a[i]] = 1;
            }
        }
    }

    int sum = 0;
    int ans = 1;
    for(int i = 1; i <= n * m; i++){
        if(sum + s[i] > i){
            cout << 0 << endl;
            return 0;
        }
        if(not t[i]){
            int tmp = 1;
            int x = i - sum;
            rep(j, s[i]){
                tmp *= x;
                tmp %= MOD;
                x--;
            }
            if(u[i]){
                int x = i - sum - 1;
                int tmp2 = 1;
                rep(j, s[i]){
                    tmp2 *= x;
                    tmp2 %= MOD;
                    x--;
                }
                tmp = (tmp + MOD - tmp2) % MOD;
            }
            ans *= tmp;
            ans %= MOD;
        }
        sum += s[i];
    }

    cout << ans << endl;

    return 0;
}
