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

bool compare(const P a, const P b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second > b.second;
}

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
    int n;
    cin >> n;

    map<int, vector<P>> m;
    m[0] = vector<P>();
    m[0].emplace_back(0, 0);

    vector<int> l;
    l.push_back(0);
    rep(i, n){
        int x, y;
        cin >> x >> y;

        int level = max(x, y);
        if(m.find(level) == m.end()){
            m[level] = vector<P>();
            l.push_back(level);
        }
        m[level].emplace_back(x, y);
    }

    sort(l.begin(), l.end());
    for(int level : l){
        sort(m[level].begin(), m[level].end(), compare);
    }

    vector<vector<P>> edge(l.size() * 2, vector<P>());
    rep(i, (int)l.size() - 1){
        P pa[2], pb[2];
        pa[0] = m[l[i]][0];
        pa[1] = m[l[i]][m[l[i]].size()-1];
        pb[0] = m[l[i+1]][0];
        pb[1] = m[l[i+1]][m[l[i+1]].size()-1];
        int lenB = abs(pb[0].first - pb[1].first) + abs(pb[0].second - pb[1].second);

        rep(a, 2){
            rep(b, 2){
                int len = abs(pa[a].first - pb[b].first)
                    + abs(pa[a].second - pb[b].second) + lenB;
                edge[i*2+a].emplace_back((i+1)*2+1-b, len);
            }
        }
    }

    int ll = l.size();
    vector<int> d1 = dijkstra<int>(edge, l.size()*2, 0).first;
    vector<int> d2 = dijkstra<int>(edge, l.size()*2, 1).first;

    cout << min(min(d1[ll*2-1], d1[ll*2-2]), min(d2[ll*2-1], d2[ll*2-2])) << endl;

    return 0;
}
