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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> x(n), y(n);
    x[0] = a[0];
    y[n-1] = a[n-1];
    for(int i = 0; i < n - 1; i++){
        x[i+1] = gcd(x[i], a[i+1]);
    }
    for(int i = n - 1; i > 0; i--){
        y[i-1] = gcd(y[i], a[i-1]);
    }

    int ans = 0;
    rep(i, n){
        if(i == 0){
            ans = max(ans, y[i+1]);
            continue;
        }
        if(i == n - 1){
            ans = max(ans, x[i-1]);
            continue;
        }
        ans = max(ans, gcd(x[i-1], y[i+1]));
    }
    cout << ans << endl;

    return 0;
}
