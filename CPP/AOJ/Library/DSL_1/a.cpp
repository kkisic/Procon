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
class union_find{
    public:
        int n;
        vector<T> p, rank;

        union_find(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

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
                rank[u]++;
            }

            p[v_root] = u_root;
        }
};

signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> p(n, -1);

    union_find<int> uf(n);
    rep(i, q){
        int com, x, y;
        cin >> com >> x >> y;

        if(com == 0){
            uf.unite(x, y);
        }

        if(com == 1){
            int px = uf.find(x);
            int py = uf.find(y);

            cout << (px == py ? 1 : 0) << endl;
        }
    }

    return 0;
}
