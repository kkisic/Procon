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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> s;
    rep(i, n){
        if(s.find(a[i]) == s.end()){
            s.insert(a[i]);
        }else{
            s.erase(a[i]);
        }
    }

    rep(i, q){
        int l, r, x;
        cin >> l >> r >> x;

        int ans = 0;
        int cnt = 0;
        auto it = s.lower_bound(l);
        while(it != s.end() && *it <= r){
            ans ^= *it;
            it = s.erase(it);
            cnt++;
        }
        cout << ans << endl;
        if(cnt % 2){
            if(s.find(x) == s.end()){
                s.insert(x);
            }else{
                s.erase(x);
            }
        }
    }

    return 0;
}
