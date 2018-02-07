#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;


signed main () {
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> u(m), v(m);
    vector<vector<int>> graph(n+1);

    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i];
        graph[u[i]].push_back(v[i]);
        graph[v[i]].push_back(u[i]);
    }

    priority_queue<P, vector<P>> que;
    vector<int> d(n+1);
    vector<bool> done(n+1);
    d[s] = s;
    que.push(make_pair(s, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int ver = p.second;

        if(done[ver]){
            continue;
        }
        done[ver] = true;

        for(int i = 0; i < graph[ver].size(); i++){
            int dd = min(p.first, graph[ver][i]);
            if(d[graph[ver][i]] < dd){
                d[graph[ver][i]] = dd;
                que.push(make_pair(dd, graph[ver][i]));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(i <= d[i]){
            cout << i << endl;
        }
    }

    return 0;
}
