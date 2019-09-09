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
    vector<P> p(n);
    rep(i, n){
        int x;
        cin >> x;
        p[i] = {x, i + 1};
    }
    sort(ALL(p), greater<P>());

    set<int> s;
    s.insert(-1);
    s.insert(0);
    s.insert(n+1);
    s.insert(n+2);
    s.insert(p[0].second);

    int ans = 0;
    for(int i = 1; i < n; i++){
        int pos = p[i].second;
        auto it = s.lower_bound(pos);
        int r = *it;
        it++;
        int rr = *it;
        it--;
        it--;
        int l = *it;
        it--;
        int ll = *it;
        int cnt = 0;

        if(r < n + 1){
            cnt += (pos - l) * (rr - r);
        }
        if(l > 0){
            cnt += (r - pos) * (l - ll);
        }
        ans += p[i].first * cnt;
        s.insert(pos);
    }
    cout << ans << endl;

    return 0;
}
