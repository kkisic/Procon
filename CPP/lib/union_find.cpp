template <typename T>
class union_find{
    public:
        int n;
        vector<T> p;

        union_find(int n)
            : n(n), p(n+1, -1){}

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
            p[u_root] = v_root;
        }
};
