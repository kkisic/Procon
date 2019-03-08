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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

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

    int n, m;
    cin >> n >> m;
    auto a = initVec2<int>(n, m);
    rep(i, n) rep(j, m) cin >> a[i][j];

    vector<set<int>> v(m, set<int>()), h(n, set<int>());
    rep(i, n){
        rep(j, m){
            v[j].insert(a[i][j]);
            h[i].insert(a[i][j]);
        }
    }

    vector<map<int, int>> vv(m, map<int, int>()), hh(n, map<int, int>());
    rep(i, n){
        int cnt = 0;
        for(auto it = h[i].begin(); it != h[i].end(); it++){
            hh[i][*it] = cnt++;
        }
    }
    rep(i, m){
        int cnt = 0;
        for(auto it = v[i].begin(); it != v[i].end(); it++){
            vv[i][*it] = cnt++;
        }
    }

    rep(i, n){
        rep(j, m){
            int vl = vv[j][a[i][j]];
            int vh = SZ(v[j]) - vl - 1;
            int hl = hh[i][a[i][j]];
            int hh = SZ(h[i]) - hl - 1;
            cout << max(vl, hl) + max(vh, hh) + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
