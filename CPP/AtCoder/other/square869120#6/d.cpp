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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> xr(n);
    rep(i, n){
        int x, r;
        cin >> x >> r;
        xr[i] = {x, r};
    }
    sort(ALL(xr));

    vector<double> r(n), l(n);
    rep(i, n){
        double tmp = 0;
        if(i > 0){
            tmp = r[i-1] - (xr[i].first - xr[i-1].first);
        }
        if(tmp > 0){
            r[i] += pow(tmp, 3);
        }
        r[i] += pow(xr[i].second, 3);
        r[i] = pow(r[i], 1.0 / 3.0);
    }
    for(int i = n - 1; i >= 0; i--){
        double tmp = 0;
        if(i < n - 1){
            tmp = l[i+1] - (xr[i+1].first - xr[i].first);
        }
        if(tmp > 0){
            l[i] += pow(tmp, 3);
        }
        l[i] += pow(xr[i].second, 3);
        l[i] = pow(l[i], 1.0 / 3.0);
    }

    double ans = 0;
    rep(i, n){
        double tmp = pow(r[i], 3) + pow(l[i], 3) - pow(xr[i].second, 3);
        tmp = pow(tmp, 1.0 / 3.0);
        ans = max(ans, tmp);
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
