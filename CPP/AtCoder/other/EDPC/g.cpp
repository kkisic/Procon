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

class TopologicalSort{
    public:
        int n;
        vector<vector<int>> edge;
        vector<int> sorted;
        vector<int> mark;

        TopologicalSort(int n, vector<vector<int>>edge)
            : n(n), edge(edge), sorted(), mark(n) {}

        bool sort(){
            rep(i, n){
                if(mark[i] != 0){
                    continue;
                }
                if(not dfs(i)){
                    return false;
                }
            }
            return true;
        }

        //sortedが辞書順最小
        bool kahn_sort(){
            priority_queue<int, vector<int>, greater<int>> s;
            vector<int> in(n);

            rep(v, n){
                for(int u : edge[v]) in[u]++;
            }

            rep(v, n){
                if(in[v] == 0) s.push(v);
            }

            while(not s.empty()){
                int v = s.top();
                sorted.push_back(v);
                s.pop();

                for(int u : edge[v]){
                    in[u]--;
                    if(in[u] == 0){
                        s.push(u);
                    }
                }
            }

            rep(i, n){
                if(in[i] > 0){
                    return false;
                }
            }
            return true;
        }

    private:
        bool dfs(int v){
            if(mark[v] == -1){
                return false;
            }
            if(mark[v] == 1){
                return true;
            }
            mark[v] = -1;

            for(int u : edge[v]){
                if(not dfs(u)){
                    return false;
                }
            }

            mark[v] = 1;
            sorted.push_back(v);
            return true;
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>());
    rep(i, m){
        int x, y;
        cin >> x >> y;

        edge[x-1].push_back(y-1);
    }

    TopologicalSort ts(n, edge);
    ts.sort();

    vector<int> depth(n, 0);
    for(int i = n - 1; i >= 0; i--){
        int v = ts.sorted[i];
        for(int u : edge[v]){
            depth[u] = max(depth[u], depth[v] + 1);
        }
    }

    int ans = 0;
    rep(i, n){
        ans = max(ans, depth[i]);
    }
    cout << ans << endl;

    return 0;
}
