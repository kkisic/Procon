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

    int t;
    cin >> t;

    rep(i, t){
        double d;
        cin >> d;

        if(d == 0){
            cout << fixed << setprecision(10) << "Y " << 0.0 << " " << 0.0 << endl;
            continue;
        }
        if(1 <= d && d <= 3){
            cout << fixed << setprecision(10) << "N" << endl;
            continue;
        }

        double lo = 1.0;
        double hi = d / 2.0;
        rep(j, 1000){
            double mid1 = (lo + hi) / 2.0;
            double mid2 = mid1 + 1e-13;

            double f1 = abs(mid1 * (d - mid1) - d);
            double f2 = abs(mid2 * (d - mid2) - d);

            if(f1 >= f2){
                lo = mid1;
            }else{
                hi = mid2;
            }
        }

        cout << fixed << setprecision(10) << "Y " << d - lo << " " << lo << endl;
    }

    return 0;
}
