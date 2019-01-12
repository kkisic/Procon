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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int x, y, z;
    x = y = z = 0;
    rep(i, n){
        if(p[i] <= a){
            x++;
            continue;
        }
        if(p[i] >= b + 1){
            z++;
            continue;
        }
        y++;
    }
    cout << min(x, min(y, z)) << endl;

    return 0;
}
