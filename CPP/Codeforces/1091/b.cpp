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

    int n;
    cin >> n;

    vector<int> x(n), y(n), a(n), b(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n) cin >> a[i] >> b[i];

    map<P, int> m;
    rep(i, n){
        rep(j, n){
            int tx = x[i] + a[j];
            int ty = y[i] + b[j];
            P p = {tx, ty};
            if(m.find(p) == m.end()){
                m[p] = 0;
            }
            m[p]++;
        }
    }

    for(pair<P, int> p : m){
        if(p.second == n){
            cout << p.first.first << " " << p.first.second << endl;
            return 0;
        }
    }

    return 0;
}
