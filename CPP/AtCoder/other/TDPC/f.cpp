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

            node[i] += (r - l) * lazy[i] % MOD;
            node[i] %= MOD;
            if(r - l > 1){
                (lazy[i * 2 + 1] += lazy[i]) %= MOD;
                (lazy[i * 2 + 2] += lazy[i]) %= MOD;
            }
            lazy[i] = 0;
        }

        void add(int s, int t, int x, int i, int l, int r){
            eval(i, l, r);

            if(t <= l || r <= s){
                return;
            }

            if(s <= l && r <= t){
                (lazy[i] += x) %= MOD;
                eval(i, l, r);
                return;
            }

            int m = l + (r - l) / 2;
            add(s, t, x, 2 * i + 1, l, m);
            add(s, t, x, 2 * i + 2, m, r);
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
            node[i] %= MOD;
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    LazySegmentTree<int> dp(n + 1, 0, [](int a, int b){return a + b;});
    dp.add(1, k, 1);
    for(int i = 2; i <= n; i++){
        dp.add(i, min(n + 1, i + k - 1), dp.query(0, i - 1));
    }
    cout << dp.query(n, n + 1) << endl;

    return 0;
}
