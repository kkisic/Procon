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

template <typename T>
class UnionFind{
    public:
        int n;
        vector<T> p, rank;

        UnionFind(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            p[v] = find(p[v]);
            return p[v];
        }

        bool unite(int u, int v){
            u = find(u);
            v = find(v);

            if(u == v){
                return false;
            }

            if(rank[u] < rank[v]){
                swap(u, v);
            }

            if(rank[u] == rank[v]){
                rank[u]++;
            }

            p[v] = u;
            return true;
        }

        bool same(int u, int v){
            u = find(u);
            v = find(v);
            return u == v;
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edge(m);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = make_tuple(c, a, b);
    }
    sort(ALL(edge));

    auto graph = initVec2<P>(n + 1, 0);
    UnionFind<int> uf(n);
    int sum = 0;
    rep(i, m){
        int u, v, w;
        tie(w, u, v) = edge[i];
        if(uf.unite(u, v)){
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
            sum += w;
        }
    }

    auto weight = initVec2<int>(n + 1, n + 1);
    for(int i = 1; i <= n; i++){
        stack<tuple<int, int, int>> st;
        st.emplace(i, 0, 0);

        while(not st.empty()){
            int v, p, w;
            tie(v, p, w) = st.top();
            st.pop();

            weight[i][v] = w;

            for(P pp : graph[v]){
                int u = pp.first;
                int we = pp.second;
                if(u == p){
                    continue;
                }
                st.emplace(u, v, max(w, we));
            }
        }
    }

    int q;
    cin >> q;
    rep(i, q){
        int s, t;
        cin >> s >> t;

        cout << sum - weight[s][t] << endl;
    }

    return 0;
}
