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

    vector<int> a(4);
    rep(i, 4) cin >> a[i];

    vector<bool> x(4, false);
    rep(i, 4){
        if(a[i] == 1){
            x[0] = true;
        }
        if(a[i] == 9){
            x[1] = true;
        }
        if(a[i] == 7){
            x[2] = true;
        }
        if(a[i] == 4){
            x[3] = true;
        }
    }

    rep(i, 4){
        if(not x[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
