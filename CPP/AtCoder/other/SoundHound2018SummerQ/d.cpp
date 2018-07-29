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

pair<vector<int>, vector<int>> dijkstra(const vector<vector<P>>& graph, int n, int s){
    vector<int> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);

    while(!que.empty()){
        int w = que.top().first;
        int to = que.top().second;
        que.pop();

        if(d[to] < w){
            continue;
        }

        rep(i, (int)graph[to].size()){
            int from = graph[to][i].first;
            int nw = w + graph[to][i].second;
            if(nw < d[from]){
                d[from] = nw;
                p[from] = to;
                que.emplace(nw, from);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<P>> edgeA(n+1, vector<P>());
    vector<vector<P>> edgeB(n+1, vector<P>());

    rep(i, m){
        int u, v, a, b;
        cin >> u >> v >> a >> b;

        edgeA[u].emplace_back(v, a);
        edgeA[v].emplace_back(u, a);
        edgeB[u].emplace_back(v, b);
        edgeB[v].emplace_back(u, b);
    }

    pair<vector<int>, vector<int>> yen = dijkstra(edgeA, n, s);
    pair<vector<int>, vector<int>> snuk = dijkstra(edgeB, n, t);

    vector<int> ans(n+1, 0);
    for(int i = n; i > 0; i--){
        int money = 1e15;

        int yy = yen.first[i];
        int ss = snuk.first[i];
        money -= yy + ss;

        if(i == n){
            ans[n] = money;
            continue;
        }

        if(ans[i+1] < money){
            ans[i] = money;
            continue;
        }
        ans[i] = ans[i+1];
    }

    rep(i, n){
        cout << ans[i+1] << endl;
    }



    return 0;
}
