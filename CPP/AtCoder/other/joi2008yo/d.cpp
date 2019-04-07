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

    int m;
    cin >> m;
    vector<P> a(m);
    rep(i, m) cin >> a[i].first >> a[i].second;
    P base = {a[0].first, a[0].second};

    int n;
    cin >> n;
    vector<P> b(n);
    set<P> s;
    rep(i, n){
        cin >> b[i].first >> b[i].second;
        s.emplace(b[i].first, b[i].second);
    }

    for(int i = m - 1; i >= 0; i--){
        a[i].first -= a[0].first;
        a[i].second -= a[0].second;
    }

    rep(i, n){
        bool ok = true;
        rep(j, m){
            if(s.find({b[i].first + a[j].first, b[i].second + a[j].second}) == s.end()){
                ok = false;
            }
        }
        if(ok){
            cout << b[i].first - base.first << " ";
            cout << b[i].second - base.second << endl;
            return 0;
        }
    }

    return 0;
}
