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

template <typename T>
class pertially_persistent_union_find{
    private:
        int n;
        vector<T> rank, time;
        vector<vector<P>> add;
        int now;

    public:
        pertially_persistent_union_find(int n)
            : n(n), rank(n+1, 1), time(n+1, INF), add(n+1), now(0) {
                for(vector<P> &a : add){
                    a.emplace_back(0, 1);
                }
            }

        int find(int v, int t){
            if(time[v] > t){
                return v;
            }

            return find(rank[v], t);
        }

        bool unite(int u, int v){
            ++now;
            int u_root = find(u, now);
            int v_root = find(v, now);

            if(u_root == v_root){
                return false;
            }

            if(rank[u_root] < rank[v_root]){
                swap(u_root, v_root);
            }

            //親: u, 子: v
            rank[u_root] += rank[v_root];
            rank[v_root] = u_root;
            add[u_root].emplace_back(now, rank[u_root]);
            time[v_root] = now;
            return true;
        }

        int size(int v, int t){
            int v_root = find(v, t);

            int lo = 0;
            int hi = add[v_root].size();
            while(hi - lo > 1){
                int mid = (hi + lo) / 2;
                if(add[v_root][mid].first <= t){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return add[v_root][lo].second;
        }

        //(u, v)が連結になった時刻
        //非連結の場合-1
        int unioned_time(int u, int v){
            int lo = -1;
            int hi = now + 1;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                int pu = find(u, mid);
                int pv = find(v, mid);

                if(pu == pv){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }
            return hi != now + 1 ? hi : -1;
        }

        int getTime(){
            return now;
        }
};
