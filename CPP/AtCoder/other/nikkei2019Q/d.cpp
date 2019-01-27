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

int n;
vector2<int> edge;
//n : 頂点数 0-indexed
class TopologicalSort{
    public:
        int n;
        vector<vector<int>> edge;
        vector<int> sorted; //DAGの逆順
        vector<int> mark;

        TopologicalSort(int n, vector<vector<int>>edge)
            : n(n), edge(edge), sorted(), mark(n) {}

        bool sort(){
            for(int i = 0; i < n; i++){
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

            for(int v = 0; v < n; v++){
                for(int u : edge[v]) in[u]++;
            }

            for(int v = 0; v < n; v++){
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

            for(int i = 0; i < n; i++){
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

    int m;
    cin >> n >> m;
    edge = initVec2<int>(n + 1, 0);
    vector<bool> isChild(n + 1, false);
    rep(i, n - 1 + m){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        isChild[b] = true;
    }

    TopologicalSort ts(n + 1, edge);
    ts.sort();

    vector<int> par(n + 1);
    set<int> s;
    for(int i = 0; i <= n; i++){
        int v = ts.sorted[i];
        if(v == 0){
            continue;
        }
        for(int u : edge[v]){
            if(s.find(u) != s.end()){
                par[u] = v;
                s.erase(u);
            }
        }
        s.insert(v);
    }

    for(int i = 1; i <= n; i++){
        cout << par[i] << endl;
    }

    return 0;
}
