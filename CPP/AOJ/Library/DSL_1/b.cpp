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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

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

signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> p(n, -1);

    weighted_union_find<int> uf(n);
    rep(i, q){
        int com, x, y;
        cin >> com >> x >> y;

        if(com == 0){
            int w;
            cin >> w;
            uf.unite(x, y, w);
        }

        if(com == 1){
            if(uf.find(x) != uf.find(y)){
                cout << "?" << endl;
                continue;
            }
            cout << uf.diff(x, y) << endl;
        }
    }

    return 0;
}
