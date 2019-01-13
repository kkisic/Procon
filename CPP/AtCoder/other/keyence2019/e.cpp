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
class SegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        T query(int s, int t, int i, int l, int r) const {
            if(r <= s || t <= l){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node;
        T init;
        function<T(T, T)> f;

        SegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init), init(init), f(f){}

        void update(int i, const T& x){
            i += (n - 1);
            node[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                node[i] = f(node[2*i+1], node[2*i+2]);
            }
        }

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

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
};

struct edge{
    edge(int w, int u, int v):
        w(w), u(u), v(v) {}
    int w, u, v;
};

bool compare(edge a, edge b){
    return a.w < b.w;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<P> v(n);
    rep(i, n){
        v[i] = {a[i], i};
    }
    sort(ALL(v));

    vector<edge> edges;
    SegmentTree<P> lst(n+1, {INF, INF}, [](P a, P b){return (a.first < b.first ? a : b);});
    SegmentTree<P> rst(n+1, {INF, INF}, [](P a, P b){return (a.first < b.first ? a : b);});
    rep(i, n){
        int id = v[i].second;
        lst.update(id, {a[id] - d * id, id});
        rst.update(id, {a[id] + d * id, id});

        P l = lst.query(0, id);
        if(l.first != INF){
            int weight = l.first + a[id] + d * id;
            edges.emplace_back(weight, id, l.second);
        }
        P r = rst.query(id + 1, n);
        if(r.first != INF){
            int weight = r.first + a[id] - d * id;
            edges.emplace_back(weight, id, r.second);
        }
    }
    sort(ALL(edges), compare);

    UnionFind<int> uf(n);
    int ans = 0;
    rep(i, SZ(edges)){
        if(uf.unite(edges[i].u, edges[i].v)){
            ans += edges[i].w;
        }
    }
    cout << ans << endl;

    return 0;
}
