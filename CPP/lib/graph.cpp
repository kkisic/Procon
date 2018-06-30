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

pair<vector<int>, vector<int>> dijkstra(const vector<vector<P>>& graph, int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(!que.empty()){
        int w = que.top().first;
        int to = que.top().second;
        que.pop();

        if(d[to] < w){
            continue;
        }

        rep(i, (int)graph[to].size()){
            int from = graph[to][i].first;
            int nw = w + graph[to][i].second;
            if(nw < d[from]){
                d[from] = nw;
                p[from] = to;
                que.emplace(nw, from);
            }
        }
    }
    return make_pair(d, p);
}
