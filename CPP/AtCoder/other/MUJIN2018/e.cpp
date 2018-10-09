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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

vector<vector<int>> dist;
int k;

class make_graph{
    public:
        int h, w, n;
        vector<vector<bool>> able;
        vector<int> d = {1, 0, -1, 0};

        make_graph(const vector<vector<bool>>& able, int h, int w)
            : h(h), w(w), n(h*w+2), able(able) {}

        //重み付き有向グラフ
        vector<vector<P>> graph(){
            vector<vector<P>> edge(n, vector<P>());

            rep(i, h){
                rep(j, w){
                    if(not able[i][j]){
                        continue;
                    }
                    int v = i * w + j;

                    rep(k, 4){
                        int nx = i + d[k];
                        int ny = j + d[k^1];
                        int u = nx * w + ny;

                        if(0 <= nx && nx < h && 0 <= ny && ny < w && able[nx][ny]){
                            //ここでの重みは移動方向
                            edge[v].emplace_back(u, k);
                        }
                    }
                }
            }

            return edge;
        }

        int convert(int x, int y){
            return x * w + y;
        }
};

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
            int dir = edge.second;
            if(dist[dir][w % k] == INF){
                continue;
            }
            T nw = w + dist[dir][w % k] + 1;
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
    int n, m;
    string d;
    cin >> n >> m >> k >> d;

    P s, g;
    vector<vector<bool>> area(n, vector<bool>(m, true));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == 'S'){
                s = make_pair(i, j);
            }
            if(c == 'G'){
                g = make_pair(i, j);
            }
            if(c == '#'){
                area[i][j] = false;
            }
        }
    }

    //0D 1R 2U 3L
    vector<int> dd = {1, 0, -1, 0};
    string ds = "DRUL";
    dist = vector<vector<int>>(4, vector<int>(k, INF));
    vector<int> p(4, INF);
    for(int i = k-1; i >= 0; i--){
        rep(j, 4){
            if(d[i] == ds[j]){
                p[j] = min(p[j], i + k);
            }
        }
    }

    for(int i = k-1; i >= 0; i--){
        rep(j, 4){
            if(d[i] == ds[j]){
                p[j] = min(p[j], i);
            }
            if(p[j] == INF){
                continue;
            }
            dist[j][i] = p[j] - i;
        }
    }

    make_graph mg(area, n, m);
    vector<vector<P>> edge = mg.graph();
    pair<vector<int>, vector<int>> ans = dijkstra<int>(edge, n * m, mg.convert(s.first, s.second));

    if(ans.first[mg.convert(g.first, g.second)] == INF){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.first[mg.convert(g.first, g.second)] << endl;

    return 0;
}
