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

vector<map<int, int>> dijkstra(const vector<vector<pair<int, int>>>& graph, int n, int s){
    typedef pair<P, int> PP;

    vector<map<int, int>> d(n + 1);
    d[s][0] = 0;

    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.emplace(make_pair(0, 0), s);

    while(!que.empty()){
        int w = que.top().first.first;
        int c = que.top().first.second;
        int v = que.top().second;
        que.pop();

        if(d[v][c] < w){
            continue;
        }

        for(pair<int, int> edge : graph[v]){
            int u = edge.first;
            int nc, nw;
            if(edge.second == c){
                nw = w;
                nc = c;
            }else if(c == 0){
                nw = w;
                nc = edge.second;
            }else{
                nw = w + 1;
                nc = edge.second;
            }

            if(d[u].find(nc) == d[u].end()){
                d[u][nc] = INF;
            }
            if(nw < d[u][nc]){
                d[u][nc] = nw;
                que.emplace(make_pair(nw, nc), u);
            }
        }
    }
    return d;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    auto edge = initVec2<P>(n + 1, 0);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }

    auto d = dijkstra(edge, n, 1);
    int ans = INF;
    for(P p : d[n]){
        ans = min(ans, p.second);
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << (ans + 1) * k << endl;
    }

    return 0;

}
