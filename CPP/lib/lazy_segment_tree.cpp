//Range Sum Query and Range Add Query
template <typename T>
class LazySegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        void eval(int i, int l, int r){
            if(lazy[i] == 0){
                return;
            }

            node[i] += (r - l) * lazy[i];
            if(r - l > 1){
                lazy[i * 2 + 1] += lazy[i];
                lazy[i * 2 + 2] += lazy[i];
            }
            lazy[i] = 0;
        }

        void add(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return;
            }

            if(s <= l && r <= t){
                lazy[i] += x;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            add(s, t, x, 2 * i + 1, l, m);
            add(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }

        T query(int s, int t, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node, lazy;
        T init;
        function<T(T, T)> f;

        LazySegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, 0), init(init), f(f) {}

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void add(int s, int t, int x){
            add(s, t, x, 0, 0, n);
        }
};

//Range Minimum Query and Range Add Query
template <typename T>
class LazySegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        void eval(int i, int l, int r){
            if(lazy[i] != 0){
                node[i] += lazy[i];
                if(r - l > 1){
                    lazy[i * 2 + 1] += lazy[i];
                    lazy[i * 2 + 2] += lazy[i];
                }
                lazy[i] = 0;
            }
        }

        void add(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return;
            }

            if(s <= l && r <= t){
                lazy[i] += x;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            add(s, t, x, 2 * i + 1, l, m);
            add(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }

        T query(int s, int t, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return INF;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node, lazy;
        T init;
        function<T(T, T)> f;

        LazySegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, 0), init(init), f(f) {}

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void add(int s, int t, int x){
            add(s, t, x, 0, 0, n);
        }
};

//Range Minimum(Maximum) Query and Range Update Query
template <typename T>
class LazySegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        void eval(int i, int l, int r){
            if(lazy[i] != INF){
                node[i] = lazy[i];
                if(r - l > 1){
                    lazy[i * 2 + 1] = lazy[i];
                    lazy[i * 2 + 2] = lazy[i];
                }
                lazy[i] = INF;
            }
        }

        void update(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return ;
            }

            if(s <= l && r <= t){
                lazy[i] = x;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            update(s, t, x, 2 * i + 1, l, m);
            update(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }

        T query(int s, int t, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node, lazy;
        T init;
        function<T(T, T)> f;

        LazySegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, INF), init(init), f(f) {}

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void update(int s, int t, int x){
            update(s, t, x, 0, 0, n);
        }
};

//Range Sum Query and Range Update Query
template <typename T>
class LazySegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        void eval(int i, int l, int r){
            if(lazy[i] != INF){
                node[i] = (r - l) * lazy[i];
                if(r - l > 1){
                    lazy[i * 2 + 1] = lazy[i];
                    lazy[i * 2 + 2] = lazy[i];
                }
                lazy[i] = INF;
            }
        }

        void update(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return ;
            }

            if(s <= l && r <= t){
                lazy[i] = x;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            update(s, t, x, 2 * i + 1, l, m);
            update(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }

        T query(int s, int t, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node, lazy;
        T init;
        function<T(T, T)> f;

        LazySegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, INF), init(init), f(f) {}

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void update(int s, int t, int x){
            update(s, t, x, 0, 0, n);
        }
};
