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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));

    bool plus = true;
    bool minus = true;
    rep(i, n){
        if(a[i] >= 0){
            minus = false;
        }
        if(a[i] <= 0){
            plus = false;
        }
    }

    int ans = a.back() - a[0];
    vector<int> p, m;
    m.push_back(a[0]);
    for(int i = 1; i < n - 1; i++){
        ans += abs(a[i]);
        if(a[i] >= 0){
            p.push_back(a[i]);
        }else{
            m.push_back(a[i]);
        }
    }

    cout << ans << endl;
    for(int x : p){
        cout << m.back() << " " << x << endl;
        m.back() -= x;
    }
    for(int x : m){
        cout << a.back() << " " << x << endl;
        a.back() -= x;
    }

    return 0;
}
