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

    int w, h, u1, u2, d1, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;

    for(int i = h; i > 0; i--){
        w += i;
        if(i == d1){
            w -= u1;
        }
        if(i == d2){
            w -= u2;
        }
        if(w < 0){
            w = 0;
        }
    }
    cout << w << endl;

    return 0;
}
