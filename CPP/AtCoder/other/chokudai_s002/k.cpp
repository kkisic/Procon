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

    set<int> s;
    rep(i, n){
        s.insert(a[i]);
        s.insert(b[i]);
    }
    vector<int> d(s.begin(), s.end());
    map<int, int> m;
    rep(i, SZ(d)){
        m[d[i]] = i;
    }
    int dn = SZ(d);

    auto edge = initVec2<int>(dn, 0);
    rep(i, n){
        edge[m[a[i]]].push_back(m[b[i]]);
        edge[m[b[i]]].push_back(m[a[i]]);
    }

    int ans = 0;
    vector<bool> used(dn, false);
    rep(i, dn){
        if(used[i]){
            continue;
        }
        int e = 0;
        int c  = 0;
        stack<int> st;
        st.push(i);
        while(not st.empty()){
            int v = st.top();
            st.pop();
            if(used[v]){
                continue;
            }
            used[v] = true;
            c++;
            e += SZ(edge[v]);

            for(int u : edge[v]){
                if(used[u]){
                    continue;
                }
                st.push(u);
            }
        }
        ans += min(c, e / 2);
    }
    cout << ans << endl;

    return 0;
}
