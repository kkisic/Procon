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

    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<int> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());
    sort(ALL(c), greater<int>());

    vector<int> bc(y * z);
    rep(i, y){
        rep(j, z){
            bc[i*z+j] = b[i] + c[j];
        }
    }
    sort(ALL(bc), greater<int>());

    vector<int> abc(x * k);
    rep(i, x){
        rep(j, min(k, y * z)){
            abc[i*k+j] = a[i] + bc[j];
        }
    }
    sort(ALL(abc), greater<int>());

    rep(i, k){
        cout << abc[i] << endl;
    }

    return 0;
}
