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

    vector<tup> e;
    vector<P> x;
    rep(i, m){
        int u, v, c;
        cin >> u >> v >> c;
        if(c == 0){
            int w;
            cin >> w;
            e.emplace_back(w, u, v);
        }else{
            char a;
            cin >> a;
            x.emplace_back(u, v);
        }
    }
    sort(ALL(e));

    vector<int> en(SZ(e), INF), xn(SZ(x), INF);

    UnionFind<int> uf1(n);
    rep(i, SZ(e)){
        int u, v, w;
        tie(w, u, v) = e[i];
        if(uf1.unite(u, v)){
            en[i] = min(en[i], 2LL);
        }
    }
    rep(i, SZ(x)){
        if(uf1.unite(x[i].first, x[i].second)){
            xn[i] = min(xn[i], 1LL);
        }
    }
    UnionFind<int> uf2(n);
    rep(i, SZ(x)){
        if(uf2.unite(x[i].first, x[i].second)){
            xn[i] = min(xn[i], 2LL);
        }
    }
    rep(i, SZ(e)){
        int u, v, w;
        tie(w, u, v) = e[i];
        if(uf2.unite(u, v)){
            en[i] = min(en[i], 1LL);
        }
    }

    vector<tup> E;
    int sum = 0;
    int cntX = 0;
    int used = 0;
    rep(i, SZ(e)){
        if(en[i] == 1){
            int u, v, w;
            tie(w, u, v) = e[i];
            sum += w;
            used++;
        }
        if(en[i] == 2){
            E.push_back(e[i]);
        }
    }
    rep(i, SZ(x)){
        if(xn[i] == 1){
            cntX++;
            used++;
        }
    }

    int q;
    cin >> q;
    vector<P> a(q);
    rep(i, q){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(ALL(a));

    vector<int> ans(q);
    int j = 0;
    int ex = n - 1 - used;
    rep(i, q){
        int qa = a[i].first;

        while(j < ex && j < SZ(E) && get<0>(E[j]) <= qa){
            sum += get<0>(E[j]);
            j++;
        }
        ans[a[i].second] = sum + (ex - j) * qa + cntX * qa;
    }

    rep(i, q){
        cout << ans[i] << endl;
    }

    return 0;
}
