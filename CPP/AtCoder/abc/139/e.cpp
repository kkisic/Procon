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

    int n;
    cin >> n;

    int N = n * (n - 1) / 2;
    auto encode = initVec2<int>(n, n);
    vector<P> decode(N);
    int cnt = 0;
    rep(i, n){
        for(int j = i + 1; j < n; j++){
            decode[cnt] = {i, j};
            encode[i][j] = cnt++;
        }
    }

    auto edge = initVec2<int>(N, 0);
    rep(i, n){
        int pre = -1;
        rep(j, n - 1){
            int x;
            cin >> x;
            x--;
            int y = i;
            if(x > y){
                swap(x, y);
            }
            int now = encode[x][y];
            if(pre != -1){
                edge[pre].push_back(now);
            }
            pre = now;
        }
    }

    TopologicalSort ts(N, edge);
    if(not ts.sort()){
        cout << -1 << endl;
        return 0;
    }

    vector<int> deg(N);
    rep(v, N){
        for(int u : edge[v]){
            deg[u]++;
        }
    }
    queue<int> que;
    vector<bool> used(N, false);
    rep(i, N){
        if(deg[i] == 0){
            que.push(i);
        }
    }

    int ans = 0;
    while(not que.empty()){
        ans++;
        queue<int> nxt;
        while(not que.empty()){
            int v = que.front();
            que.pop();
            for(int u : edge[v]){
                deg[u]--;
                if(deg[u] == 0){
                    nxt.push(u);
                }
            }
        }
        que = nxt;
    }

    cout << ans << endl;

    return 0;
}
