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

    vector<int> a(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> c[i];

    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, n){
        pq.emplace(c[i], i);
    }

    rep(i, m){
        int t, d;
        cin >> t >> d;
        t--;

        int ans = 0;
        int use = min(a[t], d);
        ans += use * c[t];
        a[t] -= use;
        int remain = d - use;

        while(remain > 0){
            while(not pq.empty() && a[pq.top().second] == 0){
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            int id = pq.top().second;
            use = min(a[id], remain);
            ans += use * c[id];
            a[id] -= use;
            remain = remain - use;
        }
        if(remain > 0){
            cout << 0 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}
