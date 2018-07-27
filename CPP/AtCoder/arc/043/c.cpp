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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n), dic(n+1);
    rep(i, n){
        cin >> a[i+1];
        dic[a[i+1]] = i+1;
    }
    rep(i, n){
        int x;
        cin >> x;
        b[i] = dic[x];
    }

    segment_tree<int> st(n+1, 0, [](int a, int b){return a + b;});
    vector<int> inv(n+1);
    for(int i = n-1; i >= 0; i--){
        inv[b[i]] = st.query(1, b[i]);
        st.update(b[i], 1);
    }

    int sum = 0;
    rep(i, n){
        sum += inv[i+1];
    }

    if(sum % 2 != 0){
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    sum /= 2;
    vector<int> ans(n+1);
    for(int i = n; i > 0; i--){
        if(cnt + inv[i] > sum){
            int k = 1;
            rep(j, n){
                if(b[j] > i){
                    continue;
                }
                ans[k++] = b[j];
            }
            break;
        }
        ans[i] = i;
        cnt += inv[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(ans[j] > ans[j+1]){
                swap(ans[j], ans[j+1]);
                cnt++;
            }
            if(cnt == sum){
                break;
            }
        }
        if(cnt == sum){
            break;
        }
    }

    rep(i, n-1){
        cout << a[ans[i+1]] << " ";
    }
    cout << a[ans[n]] << endl;
    return 0;
}
