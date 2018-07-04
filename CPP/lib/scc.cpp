//Strongly Connected Components
class SCC{
    public:
        int n, indexed;
        vector<bool> used;
        vector<int> cmp;
        vector<vector<int>> edge;
        vector<vector<int>> rev;
        vector<int> vs;

        SCC(int _n, int indexed)
            : n(_n + indexed), indexed(indexed), used(n), cmp(n),
            edge(n, vector<int>()), rev(n, vector<int>()) {}

        void add_edge(int u, int v){
            edge[u].push_back(v);
            rev[v].push_back(u);
        }

        void dfs(int v){
            if(used[v]){
                return;
            }
            used[v] = true;

            rep(i, (int)edge[v].size()){
                dfs(edge[v][i]);
            }
            vs.push_back(v);
        }

        void rdfs(int v, int k){
            if(used[v]){
                return;
            }
            used[v] = true;
            cmp[v] = k;

            rep(i, (int)rev[v].size()){
                rdfs(rev[v][i], k);
            }
        }

        int scc(){
            for(int v = indexed; v < n; v++){
                if(used[v]){
                    continue;
                }
                dfs(v);
            }

            used.assign(n, false);
            int k = 0;
            for(int i = vs.size()-1; i >= 0; i--){
                if(used[vs[i]]){
                    continue;
                }
                rdfs(vs[i], k++);
            }
            return k;
        }

        bool is_same(int u, int v){
            return cmp[u] == cmp[v];
        }
};
