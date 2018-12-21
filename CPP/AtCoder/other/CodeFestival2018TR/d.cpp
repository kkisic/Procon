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
const double eps = 1e-9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<double, double>> line(n);
    rep(i, n){
        double x, w;
        cin >> x >> w;
        line[i] = {x, w};
    }

    double lo = -1e7;
    double hi = 1e7;
    for(int i = 0; i < 100; i++){
        double mid = (lo + hi) / 2;

        double v1 = 0;
        double v2 = 0;
        rep(j, n){
            v1 = max(v1, abs(line[j].first - mid) * line[j].second);
            v2 = max(v2, abs(line[j].first - mid - eps) * line[j].second);
        }

        if(v1 > v2){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout << fixed << setprecision(10) << lo << endl;

    return 0;
}
