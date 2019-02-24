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

int upper_bound(vector<int>& a, int x){
    int n = a.size();

    int lo = -1;
    int hi = n - 1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(a[mid] >= x){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    return a[hi];
}

int lower_bound(vector<int>& a, int x){
    int n = a.size();

    int lo = 0;
    int hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(a[mid] <= x){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return a[lo];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, q;
    cin >> a >> b >> q;
    vector<int> s(a+2), t(b+2);
    rep(i, a) cin >> s[i+1];
    rep(i, b) cin >> t[i+1];
    s[0] = t[0] = -INF;
    s[a+1] = t[b+1] = INF;

    rep(i, q){
        int x;
        cin >> x;

        int sH = upper_bound(s, x);
        int sL = lower_bound(s, x);
        int tH = upper_bound(t, x);
        int tL = lower_bound(t, x);

        int ans = INF;
        ans = min(ans, max(sH, tH) - x);
        ans = min(ans, x - min(sL, tL));
        ans = min(ans, sH * 2 - x - tL);
        ans = min(ans, tH * 2 - x - sL);
        ans = min(ans, sH + x - tL * 2);
        ans = min(ans, tH + x - sL * 2);
        cout << ans << endl;
    }

    return 0;
}
