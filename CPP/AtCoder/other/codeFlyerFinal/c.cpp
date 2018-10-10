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
            node[i] = x;
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

signed main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<int> p(n+1);
    int maxP = 0;
    int minP = INF;
    rep(i, n){
        p[i+1] = p[i] + (s[i] == '(' ? 1 : -1);
        maxP = max(maxP, p[i+1]);
        minP = min(minP, p[i+1]);
    }
    int BIAS = abs(minP);

    vector<vector<int>> pp(maxP + 1 + BIAS, vector<int>());
    rep(i, n+1){
        pp[p[i]+BIAS].push_back(i);
    }

    //Range Minimum Query
    segment_tree<int> st(n+1, INF, [](int a, int b){return min(a, b);});
    int ans = 0;
    rep(i, maxP+1+BIAS){
        int l = 0;
        int r;
        st.update(l, i);
        for(r = 0; r < (int)pp[i].size(); r++){
            st.update(pp[i][r], i);

            if(s[pp[i][l]] == ')'){
            }

            if(st.query(pp[i][l], pp[i][r]+1) >= i){
                continue;
            }
            ans += (r - 1 - l) * (r - l) / 2;
            l = r;
        }
        ans += (r - 1 - l) * (r - l) / 2;
    }

    cout << ans << endl;

    return 0;
}
