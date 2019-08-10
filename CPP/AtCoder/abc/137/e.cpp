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

typedef tuple<int, int, int> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<tup> vt(m);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        vt[i] = make_tuple(a, b, c);
    }

    auto edge = initVec2<int>(n + 1, 0);
    rep(i, m){
        int a, b, c;
        tie(a, b, c) = vt[i];

        edge[b].push_back(a);
    }
    vector<bool> used(n + 1, false);
    stack<int> st;
    st.push(n);
    while(not st.empty()){
        int v = st.top();
        st.pop();

        if(used[v]){
            continue;
        }
        used[v] = true;

        for(int u : edge[v]){
            if(used[u]){
                continue;
            }
            st.push(u);
        }
    }
    //Bellman-Ford
    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);
    dist[1] = 0;
    bool negative_cycle = false;
    for (int i = 0;; i++) {
        bool update = false;
        rep(i, m){
            int a, b, c;
            tie(a, b, c) = vt[i];

            if(not used[a] || not used[b]){
                continue;
            }
            if (dist[a] != INF && dist[b] > dist[a] - c + p) {
                dist[b] = dist[a] - c + p;
                prev[b] = a;
                update = true;
            }
        }
        if (!update) break;
        if (i > n) { negative_cycle = true; break; }
    }

    if(negative_cycle){
        cout << -1 << endl;
    }else{
        cout << max(-dist[n], 0LL) << endl;
    }
    return 0;
}
