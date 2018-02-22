
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

pair<vector<int>, vector<int>> dijkstra(const vector<vector<edge>>& graph, int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+k, -1);
    p[s] =  s;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, s));

    while(!q.empty()){
        P p = que.top();
        int to = p.second;
        que.pop();

        if(d[to] < p.first){
            continue;
        }

        for(int i = 0; i < graph[to].size(); i++){
            edge e = graph[to][i];
            if(d[e.v] > d[to] + e.w){
                d[e.v] = d[to] + e.w;
                p[e.v] = e.u;
                que.push(make_pair(d[e.v], e.v));
            }
        }
    }
    return make_pair(d, p);
}
