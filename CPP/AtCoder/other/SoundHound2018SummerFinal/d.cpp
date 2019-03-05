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

vector<queue<int>> vq;
set<P> query;

void connect(UnionFind<int>& uf, int v){
    while(not vq[v].empty()){
        int u = vq[v].front();
        uf.unite(v, u);
        vq[v].pop();
        connect(uf, u);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vq = vector<queue<int>>(n + 1, queue<int>());
    UnionFind<int> uf(n);

    rep(i, q){
        int t, u, v;
        cin >> t >> u >> v;

        if(u < v){
            swap(u, v);
        }

        if(t == 1){
            if(uf.same(u, v)){
                continue;
            }
            if(query.find({u, v}) != query.end()){
                continue;
            }
            query.emplace(u, v);
            u = uf.find(u);
            v = uf.find(v);
            vq[u].push(v);
            vq[v].push(u);
        }else if(t == 2){
            connect(uf, uf.find(u));
        }else{
            if(uf.same(u, v) || query.find({u, v}) != query.end()){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
