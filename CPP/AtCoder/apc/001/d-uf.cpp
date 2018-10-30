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
class union_find{
    public:
        int n;
        vector<T> p, rank;

        union_find(int n)
            : n(n), p(n, -1), rank(n) {}

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
                rank[u_root]++;
            }

            p[v_root] = u_root;
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    union_find<int> uf(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    if(m == n - 1){
        cout << 0 << endl;
        return 0;
    }

    if(n < 2 * (n - m - 1)){
        cout << "Impossible" << endl;
        return 0;
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> used(n, false);
    rep(i, n){
        pq.emplace(a[i], uf.find(i));
    }

    int ans = 0;
    int remain = 2 * (n - m - 1) - (n - m);
    rep(i, n){
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(not used[v]){
            used[v] = true;
            ans += cost;
            continue;
        }

        if(remain > 0){
            ans += cost;
            remain--;
        }
    }
    cout << ans << endl;

    return 0;
}
