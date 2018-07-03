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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
class lazy_segment_tree{
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
                    lazy[i * 2 + 1] = lazy[i] / 2;
                    lazy[i * 2 + 2] = lazy[i] / 2;
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
                lazy[i] = (r - l) * x;
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

        lazy_segment_tree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init) , lazy(calc_size(n) * 2, INF), init(init), f(f) {}

        T query(int s, int t){
            return query(s, t, 0, 0, n);
        }

        void update(int s, int t, int x){
            update(s, t, x, 0, 0, n);
        }
};

signed main(){
    int n, q;
    cin >> n >> q;

    lazy_segment_tree<int> lst(n, 0, [](int a, int b){return a+b;});

    rep(i, q){
        int que, s, t;
        cin >> que >> s >> t;

        if(que == 0){
            int x;
            cin >> x;
            lst.update(s, t+1, x);
        }else{
            cout << lst.query(s, t+1) << endl;
        }
    }

    return 0;
}
