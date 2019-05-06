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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> p(m);
    rep(i, m) cin >> p[i];

    sort(ALL(x));
    int g = 0;
    rep(i, n - 1){
        if(i == 0){
            g = x[i+1] - x[i];
            continue;
        }
        g = gcd(g, x[i+1] - x[i]);
    }

    int idx = -1;
    rep(i, m){
        if(g % p[i] == 0){
            idx = i + 1;
        }
    }

    if(idx == -1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << x[0] << " " << idx << endl;

    return 0;
}
