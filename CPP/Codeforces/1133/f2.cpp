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

    int n, m, d;
    cin >> n >> m >> d;

    auto graph = initVec2<int>(n + 1, 0);
    vector<P> edge(m);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[i] = {u, v};
    }

    if(SZ(graph[1]) < d){
        cout << "NO" << endl;
        return 0;
    }

    UnionFind<int> uf(n);
    rep(i, m){
        int u = edge[i].first;
        int v = edge[i].second;
        if(u == 1 || v == 1){
            continue;
        }
        uf.unite(u, v);
    }
    int cnt = 0;
    vector<int> need;
    for(int v : graph[1]){
        if(uf.unite(1, v)){
            need.push_back(v);
            cnt++;
        }
    }

    if(cnt > d){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    uf = UnionFind<int>(n);
    for(int v : need){
        uf.unite(1, v);
        d--;
        cout << 1 << " " << v << endl;
    }
    for(int v : graph[1]){
        if(d > 0 && uf.unite(1, v)){
            d--;
            cout << 1 << " " << v << endl;
        }
    }
    rep(i, m){
        int u = edge[i].first;
        int v = edge[i].second;
        if(u == 1 || v == 1){
            continue;
        }
        if(uf.unite(u, v)){
            cout << u << " " << v << endl;
        }
    }

    return 0;
}
