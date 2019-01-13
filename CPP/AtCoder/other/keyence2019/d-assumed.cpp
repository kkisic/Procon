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
    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());

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

    vector<bool> both(n * m + 1, false), exist(n * m + 1, false);
    rep(i, n){
        rep(j, m){
            int x = min(a[i], b[j]);
            exist[x] = true;
            if(a[i] == b[j]){
                both[x] = true;
            }
        }
    }

    if(not both[n*m]){
        cout << 0 << endl;
        return 0;
    }

    int sum = 0;
    int row = 0;
    int column = 0;
    int ans = 1;
    for(int i = n * m; i >= 1; i--){
        if(row + 1 < n && a[row+1] == i){
            row++;
        }
        if(column + 1 < m && b[column+1] == i){
            column++;
        }

        if(both[i]){
            continue;
        }

        if(exist[i]){
            if(a[row] == i){
                ans *= (column + 1);
            }else{
                ans *= (row + 1);
            }
            ans %= MOD;
            continue;
        }

        int tmp = (row + 1) * (column + 1);
        tmp -= n * m - i;
        ans *= tmp;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
