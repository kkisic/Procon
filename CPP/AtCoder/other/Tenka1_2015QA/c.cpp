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

struct edge_flow{int to, cap, rev;};

class FordFulkerson{
    public:
        int n;
        vector<vector<edge_flow>> edge;
        vector<bool> used;

        FordFulkerson(const vector<vector<edge_flow>>& edge, int n)
            : n(n), edge(edge){}

        int dfs(int v, int t, int f){
            if(v == t){
                return f;
            }
            used[v] = true;

            for(int i = 0; i < (int)edge[v].size(); i++){
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    auto a = initVec2<int>(h, w);
    auto b = initVec2<int>(h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];

    int n = h * w + 2;
    auto edge = initVec2<edge_flow>(n, 0);

    vector<int> d = {1, 0, -1, 0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == b[i][j]){
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

            for(int k = 0; k < 4; k++){
                int nx = i + d[k];
                int ny = j + d[k^1];
                int u = nx * w + ny + 1;

                if(0 <= nx && nx < h && 0 <= ny && ny < w && a[nx][ny] != b[nx][ny] && a[i][j] != a[nx][ny]){
                    edge[v].push_back(edge_flow{u, 1, (int)edge[u].size()});
                    edge[u].push_back(edge_flow{v, 0, (int)edge[v].size() - 1});
                }
            }
        }
    }

    FordFulkerson ff(edge, n);
    int p = ff.max_flow(0, n - 1);
    int cnt = 0;
    rep(i, h) rep(j, w){
        if(a[i][j] != b[i][j]){
            cnt++;
        }
    }
    cout << cnt - p << endl;

    return 0;
}
