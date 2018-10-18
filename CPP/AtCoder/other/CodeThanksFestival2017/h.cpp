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
class pertially_persistent_union_find{
    private:
        int n;
        vector<T> p, rank, time;
        int now;

    public:
        pertially_persistent_union_find(int n)
            : n(n), p(n+1, -1), rank(n+1), time(n+1, INF), now(0) {}

        int find(int v, int t){
            if(time[v] > t){
                return v;
            }

            return find(p[v], t);
        }

        bool unite(int u, int v){
            ++now;
            int u_root = find(u, now);
            int v_root = find(v, now);

            if(u_root == v_root){
                return false;
            }

            if(rank[u_root] < rank[v_root]){
                swap(u_root, v_root);
            }

            if(rank[u_root] == rank[v_root]){
                rank[u_root]++;
            }

            p[v_root] = u_root;
            time[v_root] = now;
            return true;
        }

        //(u, v)が連結になった時刻
        //非連結の場合-1
        int unioned_time(int u, int v){
            int lo = -1;
            int hi = now + 1;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                int pu = find(u, mid);
                int pv = find(v, mid);

                if(pu == pv){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }
            return hi != now + 1 ? hi : -1;
        }

        int getTime(){
            return now;
        }
};

signed main(){
    int n, m;
    cin >> n >> m;

    pertially_persistent_union_find<int> uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    int q;
    cin >> q;
    rep(i, q){
        int x, y;
        cin >> x >> y;
        cout << uf.unioned_time(x, y) << endl;
    }

    return 0;
}
