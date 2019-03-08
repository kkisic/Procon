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
    a = abs(a);
    b = abs(b);
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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    map<P, int> m;
    int ans = 0;
    int zero = 0;
    rep(i, n){
        if(b[i] == 0){
            if(a[i] == 0){
                zero++;
            }else{
                ans++;
            }
            continue;
        }
        if(a[i] == 0){
            continue;
        }
        if(a[i] < 0){
            a[i] *= -1;
            b[i] *= -1;
        }
        int g = gcd(a[i], b[i]);
        m[{a[i]/g, b[i]/g}]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        ans = max(ans, it->second);
    }
    cout << ans + zero << endl;

    return 0;
}
