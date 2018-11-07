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

    int r, c;
    cin >> r >> c;

    int ans = 0;
    for(int i = c; i <= r; i += c){
        for(int j = c; j <= r; j += c){
            double dist = pow(i, 2) + pow(j, 2);
            if(dist <= pow(r, 2)){
                ans++;
            }
        }
    }
    cout << ans * 4 << endl;

    return 0;
}
