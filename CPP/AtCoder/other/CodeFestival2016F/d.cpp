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

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    sort(ALL(x));

    auto a = initVec2<P>(m, 0);
    rep(i, n){
        int y = x[i] % m;
        if(a[y].empty() || a[y].back().first != x[i]){
            a[y].emplace_back(x[i], 0);
        }
        a[y].back().second++;
    }

    int ans = 0;
    for(int i = 0; i <= m / 2; i++){
        int j = m - i;

        int ci = 0;
        int di = 0;
        for(P p : a[i]){
            ci += p.second;
            di += p.second / 2;
        }
        if(i == 0 || (i == m / 2 && m % 2 == 0)){
            ans += ci / 2;
            continue;
        }

        int cj = 0;
        int dj = 0;
        for(P p : a[j]){
            cj += p.second;
            dj += p.second / 2;
        }

        if(ci < cj){
            swap(ci, cj);
            swap(di, dj);
        }

        ans += cj + min(di, (ci - cj) / 2);
    }
    cout << ans << endl;

    return 0;
}
