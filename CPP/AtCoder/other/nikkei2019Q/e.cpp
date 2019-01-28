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
};

struct edge{
    int w, x, y;
};

bool compare(edge a, edge b){
    return a.w < b.w;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1);
    rep(i, n){
        cin >> x[i+1];
    }

    auto graph = initVec2<P>(n + 1, 0);
    vector<edge> ve(m);
    rep(i, m){
        int a, b, y;
        cin >> a >> b >> y;
        ve[i] = {y, a, b};
        graph[a].emplace_back(b, y);
        graph[b].emplace_back(a, y);
    }
    sort(ALL(ve), compare);

    UnionFind<int> uf(n + 1);
    vector<int> sum(n + 1); //連結成分の頂点の重みの和
    rep(i, n + 1){
        sum[i] = x[i];
    }

    //辺の重みの昇順にMSTを構築
    stack<edge> st; //必ず採用する辺
    rep(i, m){
        int rx = uf.find(ve[i].x);
        int ry = uf.find(ve[i].y);
        int s = sum[rx] + sum[ry];
        //接続可能なら根の和を更新
        if(uf.unite(ve[i].x, ve[i].y)){
            sum[uf.find(rx)] = s;
        }
        //連結成分の頂点の重みの和が辺の重み以上なら採用
        if(sum[uf.find(rx)] >= ve[i].w){
            st.push(ve[i]);
        }
    }

    vector<bool> used(n + 1, false);
    int ans = 0; //採用可能な辺の総数
    //採用する辺の重みの降順に処理
    //採用する辺の重み以下の連結可能な辺を全て採用する
    while(not st.empty()){
        edge e = st.top();
        st.pop();

        stack<int> next;
        next.push(e.x);

        while(not next.empty()){
            int v = next.top();
            next.pop();

            if(used[v]){
                continue;
            }
            used[v] = true;

            for(P p : graph[v]){
                int u = p.first;
                int w = p.second;
                if(w <= e.w && not used[u]){
                    ans++;
                    next.push(u);
                }
            }
        }
    }

    cout << m - ans << endl;

    return 0;
}
