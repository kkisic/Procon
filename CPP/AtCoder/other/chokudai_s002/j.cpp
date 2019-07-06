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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int ans = 1;
    for(int i = 1; i * i <= a[0]; i++){
        if(a[0] % i){
            continue;
        }
        int x;
        bool ok;

        x = i;
        ok = true;
        rep(j, n){
            if(a[j] % x && b[j] % x){
                ok = false;
            }
        }
        if(ok){
            ans = max(ans, x);
        }

        x = a[0] / i;
        ok = true;
        rep(j, n){
            if(a[j] % x && b[j] % x){
                ok = false;
            }
        }
        if(ok){
            ans = max(ans, x);
        }
    }
    for(int i = 1; i * i <= b[0]; i++){
        if(b[0] % i){
            continue;
        }
        int x;
        bool ok;

        x = i;
        ok = true;
        rep(j, n){
            if(a[j] % x && b[j] % x){
                ok = false;
            }
        }
        if(ok){
            ans = max(ans, x);
        }

        x = b[0] / i;
        ok = true;
        rep(j, n){
            if(a[j] % x && b[j] % x){
                ok = false;
            }
        }
        if(ok){
            ans = max(ans, x);
        }
    }
    cout << ans << endl;

    return 0;
}
