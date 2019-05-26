#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

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
                node[i] = f(node[i], lazy[i]);
                if(r - l > 1){
                    lazy[i * 2 + 1] = f(lazy[i], lazy[i * 2 + 1]);
                    lazy[i * 2 + 2] = f(lazy[i], lazy[i * 2 + 2]);
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
                lazy[i] = f(lazy[i], x);
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            update(s, t, x, 2 * i + 1, l, m);
            update(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[i], f(node[2 * i + 1], node[2 * i + 2]));
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> s(n), t(n), x(n), d(q);
    rep(i, n) cin >> s[i] >> t[i] >> x[i];
    rep(i, q) cin >> d[i];

    LazySegmentTree<int> lst(q + 1, INF, [](int a, int b){return min(a,b);});
    vector<P> range(n);
    rep(i, n){
        int mini = s[i] - x[i];
        int maxi = t[i] - x[i];

        int lo = -1;
        int hi = q - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(d[mid] >= mini){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        int mindex = hi;
        if(d[mindex] < mini){
            mindex = q;
        }

        lo = -1;
        hi = q - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(d[mid] >= maxi){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        int maxdex = hi;
        if(d[maxdex] < maxi){
            maxdex = q;
        }

        lst.update(mindex, maxdex, x[i]);
    }

    rep(i, q){
        int ans = lst.query(i, i + 1);
        if(ans == INF){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}
