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
pair<vector<T>, vector<int>> dijkstra(const vector<vector<pair<int, T>>>& graph, int n, int s){
    typedef pair<T, int> PP;

    vector<T> d(n+1, INF);
    d[s] = 0;

    vector<int> p(n+1, -1);
    p[s] =  s;

    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.emplace((T)0, s);

    while(!que.empty()){
        T w = que.top().first;
        int v = que.top().second;
        que.pop();

        if(d[v] < w){
            continue;
        }

        for(pair<int, T> edge : graph[v]){
            int u = edge.first;
            T nw = w + edge.second;
            if(nw < d[u]){
                d[u] = nw;
                p[u] = v;
                que.emplace(nw, u);
            }
        }
    }
    return make_pair(d, p);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    map<P, int> mdic;
    vector<vector<P>> edge(n+1, vector<P>());
    rep(i, m){
        int x, y, w;
        cin >> x >> y >> w;

        edge[x].emplace_back(y, w);
        edge[y].emplace_back(x, w);
        mdic[make_pair(x, y)] = i + 1;
        mdic[make_pair(y, x)] = i + 1;
    }

    pair<vector<int>, vector<int>> res = dijkstra<int>(edge, n, 1);
    vector<int> d = res.first;
    vector<int> p = res.second;


    queue<int> q;
    q.emplace(1);
    vector<int> used(m+1, false);
    int cnt = 0;
    while(not q.empty()){
        int v = q.front();
        q.pop();

        for(P pp : edge[v]){
            int u = pp.first;
            if(p[u] == v){
                if(cnt < k){
                    q.emplace(u);
                    used[mdic[make_pair(u, v)]] = true;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    vector<int> ans;
    rep(i, m+1){
        if(used[i]){
            ans.push_back(i);
        }
    }

    if(cnt > 0){
        cout << ans[0];
    }
    for(int i = 1; i < cnt; i++){
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
