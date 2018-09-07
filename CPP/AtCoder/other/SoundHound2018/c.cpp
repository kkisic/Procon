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

struct edge_flow{int to, cap, rev;};

class ford_fulkerson{
    public:
        int n;
        vector<vector<edge_flow>> edge;
        vector<bool> used;

        ford_fulkerson(const vector<vector<edge_flow>>& edge, int n)
            : n(n), edge(edge){}

        int dfs(int v, int t, int f){
            if(v == t){
                return f;
            }
            used[v] = true;

            rep(i, (int)edge[v].size()){
                edge_flow &e = edge[v][i];
                if(not used[e.to] && e.cap > 0){
                    int d = dfs(e.to, t, min(f, e.cap));
                    if(d > 0){
                        e.cap -= d;
                        edge[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        int max_flow(int s, int t){
            int flow = 0;
            while(true){
                used = vector<bool>(n+1, false);
                int f = dfs(s, t, INF);
                if(f == 0){
                    return flow;
                }
                flow += f;
            }
        }
};

class make_graph{
    public:
        int h, w, n;
        vector<vector<bool>> able;
        vector<int> d = {1, 0, -1, 0};

        make_graph(const vector<vector<bool>>& able, int h, int w)
            : h(h), w(w), n(h*w+2), able(able) {}

        vector<vector<edge_flow>> flow(){
            vector<vector<edge_flow>> edge(n, vector<edge_flow>());

            rep(i, h){
                rep(j, w){
                    if(not able[i][j]){
                        continue;
                    }

                    int v = i * w + j + 1;
                    if((i + j) % 2 != 0){
                        edge[v].push_back(edge_flow{n-1, 1, (int)edge[n-1].size()});
                        edge[n-1].push_back(edge_flow{v, 0, (int)edge[v].size() - 1});
                        continue;
                    }
                    edge[0].push_back(edge_flow{v, 1, (int)edge[v].size()});
                    edge[v].push_back(edge_flow{0, 0, (int)edge[0].size() - 1});

                    rep(k, 4){
                        int nx = i + d[k];
                        int ny = j + d[k^1];
                        int u = nx * w + ny + 1;

                        if(0 <= nx && nx < h && 0 <= ny && ny < w && able[nx][ny]){
                            edge[v].push_back(edge_flow{u, 1, (int)edge[u].size()});
                            edge[u].push_back(edge_flow{v, 0, (int)edge[v].size() - 1});
                        }
                    }
                }
            }

            return edge;
        }
};

signed main(){
    int r, c;
    cin >> r >> c;

    vector<vector<bool>> area(r, vector<bool>(c, false));
    int n = 0;
    rep(i, r){
        rep(j, c){
            char c;
            cin >> c;

            if(c == '.'){
                area[i][j] = true;
                n++;
            }
        }
    }

    make_graph mg(area, r, c);
    ford_fulkerson ff(mg.flow(), mg.n);

    cout << n - ff.max_flow(0, mg.n - 1) << endl;

    return 0;
}
