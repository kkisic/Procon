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
const double EPS = 1e-9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    rep(i, t){
        double n;
        cin >> n;

        if(n == 179){
            cout << 360 << endl;
            continue;
        }

        int ans = INF;
        for(int x = 3; x <= 360; x++){
            double ang = 180.0 / x;

            for(int j = 1; j <= x - 2; j++){
                if(ang * j - EPS <= n && n <= ang * j + EPS){
                    ans = min(ans, x);
                }
            }
        }

        if(ans == INF){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}
