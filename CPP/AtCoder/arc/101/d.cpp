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

int n;
vector<int> a;

//Range Sum Query
//segment_tree<int> st(n+1, 0, [](int a, int b){return a+b;});

template <typename T>
class segment_tree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        T query(int s, int t, int i, int l, int r) const {
            if(r <= s || t <= l){
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
        vector<T> node;
        T init;
        function<T(T, T)> f;

        segment_tree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init), init(init), f(f){}

        void update(int i, const T& x){
            i += (n - 1);
            node[i] += x;
            while(i > 0){
                i = (i - 1) / 2;
                node[i] = f(node[2*i+1], node[2*i+2]);
            }
        }

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};

int solve(int x){
    vector<int> s(n+1);
    s[0] = 0;
    int min = s[0];
    for(int i = 0; i < n; i++){
        s[i+1] = s[i] + (a[i] < x ? -1 : 1);

        if(s[i+1] < min){
            min = s[i+1];
        }
    }

    min = abs(min);
    rep(i, n+1){
        s[i] += min;
    }

    segment_tree<int> st(n+1, 0, [](int a, int b){return a+b;});
    int inv = 0;
    rep(i, n+1){
        inv += st.query(0, s[i]+1);
        st.update(s[i], 1);
    }

    return inv;
}

signed main(){
    cin >> n;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];
    int m = (1 + n) * n / 2;
    m = (m+1) / 2;

    int lo = 1;
    int hi = 1e9+1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(solve(mid) >= m){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << lo << endl;

    return 0;
}
