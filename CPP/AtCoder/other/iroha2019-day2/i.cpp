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
pair<vector<T>, vector<int>> dijkstra(const vector<vector<pair<int, T>>>& graph, int n, int s){
    typedef pair<T, int> PP;

    vector<T> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.emplace((T)0, s);

    while(!que.empty()){
        T w = que.top().first;
        int v = que.top().second;
        que.pop();

        if(d[v] < w){
            continue;
        }

        for(pair<int, T> edge : graph[v]){
            int u = edge.first;
            T nw = w + edge.second;
            if(nw < d[u]){
                d[u] = nw;
                p[u] = v;
                que.emplace(nw, u);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, x;
    cin >> h >> w >> x;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    int s = (sx - 1) * w + sy - 1;
    int g = (gx - 1) * w + gy - 1;
    vector<int> a(h * w);
    rep(i, h) rep(j, w) cin >> a[i*w+j];
    vector<int> c(x + 1);
    rep(i, x) cin >> c[i+1];

    auto edge = initVec2<P>(h * w, 0);
    vector<int> d = {1, 0, -1, 0};
    rep(i, h) rep(j, w){
        int v = i * w + j;

        rep(k, 4){
            int nx = i + d[k];
            int ny = j + d[k^1];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                continue;
            }
            int u = nx * w + ny;
            int cost = a[v] == a[u] ? 0 : c[a[u]];
            edge[v].emplace_back(u, cost);
        }
    }

    auto res = dijkstra<int>(edge, h * w, s);
    cout << res.first[g] << endl;

    return 0;
}
