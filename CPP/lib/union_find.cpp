template <typename T>
class UnionFind{
    public:
        int n;
        vector<T> p, rank;

        UnionFind(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            p[v] = find(p[v]);
            return p[v];
        }

        bool unite(int u, int v){
            u = find(u);
            v = find(v);

            if(u == v){
                return false;
            }

            if(rank[u] < rank[v]){
                swap(u, v);
            }

            if(rank[u] == rank[v]){
                rank[u]++;
            }

            p[v] = u;
            return true;
        }

        bool same(int u, int v){
            u = find(u);
            v = find(v);
            return u == v;
        }
};

template <typename T>
class WeightedUnionFind{
    public:
        int n;
        vector<T> p, w, rank;

        WeightedUnionFind(int n)
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

        bool unite(int u, int v, int ww){
            ww = ww + weight(u) - weight(v);
            u = find(u);
            v = find(v);

            if(u == v){
                return false;
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
            return true;
        }
};

template <typename T>
class PertiallyPersistentUnionFind{
    private:
        int n;
        vector<T> rank, time;
        vector<vector<P>> add;
        int now;

    public:
        PertiallyPersistentUnionFind(int n)
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
            u = find(u, now);
            v = find(v, now);

            if(u == v){
                return false;
            }

            if(rank[u] < rank[v]){
                swap(u, v);
            }

            //親: u, 子: v
            rank[u] += rank[v];
            rank[v] = u;
            add[u].emplace_back(now, rank[u]);
            time[v] = now;
            return true;
        }

        int size(int v, int t){
            v = find(v, t);

            int lo = 0;
            int hi = add[v].size();
            while(hi - lo > 1){
                int mid = (hi + lo) / 2;
                if(add[v][mid].first <= t){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return add[v][lo].second;
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
