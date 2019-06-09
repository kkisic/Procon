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
    vector<int> a(m);
    rep(i, m){
        cin >> a[i];
        if(i > 0 && a[i] == a[i-1] + 1){
            cout << 0 << endl;
            return 0;
        }
    }

    vector<int> f(100010);
    f[0] = f[1] = 1;
    for(int i = 2; i < 100010; i++){
        f[i] = f[i-1] + f[i-2];
        f[i] %= MOD;
    }

    int pos = 0;
    int ans = 1;
    rep(i, m){
        if(pos > a[i]){
            continue;
        }

        int d = a[i] - pos - 1;
        ans *= f[d];
        ans %= MOD;
        pos = a[i] + 1;
    }

    if(pos < n){
        int d = n - pos;
        ans *= f[d];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
