template <typename T>
class union_find{
    public:
        int n;
        vector<T> p, rank;

        union_find(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            p[v] = find(p[v]);
            return p[v];
        }

        void unite(int u, int v){
            int u_root = find(u);
            int v_root = find(v);

            if(u_root == v_root){
                return;
            }

            if(rank[u_root] < rank[v_root]){
                swap(u_root, v_root);
            }

            if(rank[u_root] == rank[v_root]){
                rank[u]++;
            }

            p[v_root] = u_root;
        }
};

template <typename T>
class weighted_union_find{
    public:
        int n;
        vector<T> p, w, rank;

        weighted_union_find(int n)
            : n(n), p(n+1, -1), w(n+1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            int r = find(p[v]);
            w[v] += w[p[v]];
            return p[v] = r;
        }

        int weight(int v){
            find(v);
            return w[v];
        }

        int diff(int u, int v){
            return weight(v) - weight(u);
        }

        void unite(int u, int v, int ww){
            ww = ww + weight(u) - weight(v);
            u = find(u);
            v = find(v);

            if(u == v){
                return;
            }

            if(rank[u] < rank[v]){
                swap(u, v);
                ww = -ww;
            }

            if(rank[u] == rank[v]){
                rank[u]++;
            }

            p[v] = u;
            w[v] = ww;
        }
};
