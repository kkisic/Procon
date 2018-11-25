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

    int t, a, b, c, d;
    cin >> t >> a >> b >> c >> d;

    if(t >= a + c){
        cout << b + d << endl;
        return 0;
    }

    if(t >= c){
        cout << d << endl;
        return 0;
    }

    if(t >= a){
        cout << b << endl;
        return 0;
    }
    cout << 0 << endl;

    return 0;
}
