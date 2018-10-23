//n : 頂点数
class topological_sort{
    public:
        int n;
        vector<vector<int>> edge;
        vector<int> sorted;
        vector<int> mark;

        topological_sort(int n, vector<vector<int>>edge)
            : n(n), edge(edge), sorted(), mark(n) {}

        bool sort(){
            rep(i, n+1){
                if(mark[i] != 0){
                    continue;
                }
                if(not dfs(i)){
                    return false;
                }
            }
            return true;
        }

        //sortedが辞書順最小
        bool kahn_sort(){
            priority_queue<int, vector<int>, greater<int>> s;
            vector<int> in(n);

            rep(v, n){
                for(int u : edge[v]) in[u]++;
            }

            rep(v, n){
                if(in[v] == 0) s.push(v);
            }

            while(not s.empty()){
                int v = s.top();
                sorted.push_back(v);
                s.pop();

                for(int u : edge[v]){
                    in[u]--;
                    if(in[u] == 0){
                        s.push(u);
                    }
                }
            }

            rep(i, n){
                if(in[i] > 0){
                    return false;
                }
            }
            return true;
        }

    private:
        bool dfs(int v){
            if(mark[v] == -1){
                return false;
            }
            if(mark[v] == 1){
                return true;
            }
            mark[v] = -1;

            for(int u : edge[v]){
                if(not dfs(u)){
                    return false;
                }
            }

            mark[v] = 1;
            sorted.push_back(v);
            return true;
        }
};
