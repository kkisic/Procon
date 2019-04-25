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

int n, m;
vector<double> x, y, r, s, t;

bool check(double R){
    rep(i, m){
        rep(j, n){
            double d = pow(s[i] - x[j], 2) + pow(t[i] - y[j], 2);
            if(d < pow(R + r[j], 2)){
                return false;
            }
        }
        rep(j, m){
            if(i == j){
                continue;
            }
            double d = pow(s[i] - s[j], 2) + pow(t[i] - t[j], 2);
            if(d < pow(R * 2.0, 2)){
                return false;
            }
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    x = vector<double>(n);
    y = vector<double>(n);
    r = vector<double>(n);
    s = vector<double>(m);
    t = vector<double>(m);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];
    rep(i, m) cin >> s[i] >> t[i];

    if(m == 0){
        cout << *min_element(ALL(r)) << endl;
        return 0;
    }

    double lo = 0;
    double hi = 1000;
    rep(i, 100){
        double mid = (lo + hi) / 2.0;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << fixed << setprecision(10) << lo << endl;

    return 0;
}
