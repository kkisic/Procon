class edge{
    public:
        int u;
        int v;
        int w;
        edge() : u(0), v(0), w(0) {}
        edge(int u, int v, int w) : u(u), v(v), w(w) {}

        bool operator==(const edge& e) const {
            return u == e.u && v == e.v && w == e.w;
        }

        bool operator<(const edge& e) const {
            if(w != e.w){
                return w < e.w;
            }

            return u == e.u ? v < e.v : u < e.u;
        }
};

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

class MakeGraph{
    public:
        int h, w, n;
        vector<vector<bool>> able;
        vector<int> d = {1, 0, -1, 0};

        MakeGraph(const vector<vector<bool>>& able, int h, int w)
            : h(h), w(w), n(h*w+2), able(able) {}

        //2部グラフのフローへ変換
        //座標(i, j)で(i + j)の偶奇で色分け
        //始点0, 終点n-1
        vector<vector<edge_flow>> flow(){
            vector<vector<edge_flow>> edge(n, vector<edge_flow>());

            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
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

                    for(int k = 0; k < 4; k++){
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

        //重みなし有向グラフ
        vector<vector<int>> graph(){
            vector<vector<int>> edge(n, vector<int>());

            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(not able[i][j]){
                        continue;
                    }
                    int v = i * w + j;

                    for(int k = 0; k < 4; k++){
                        int nx = i + d[k];
                        int ny = j + d[k^1];
                        int u = nx * w + ny;

                        if(0 <= nx && nx < h && 0 <= ny && ny < w && able[nx][ny]){
                            edge[v].push_back(u);
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
