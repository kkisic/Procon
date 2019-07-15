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

vector2<P> g;
vector<int> d;
vector<P> edge;
vector<bool> used;

void dfs1(int v, int p){
    if(used[v]){
        return;
    }
    used[v] = true;

    for(P pa : g[v]){
        int u = pa.first;
        int e = pa.second;
        if(u == p){
            continue;
        }
        if(used[u]){
            continue;
        }
        d[e] = 0;
        dfs1(u, v);
    }
}

void dfs2(int v, int p){
    if(used[v]){
        return;
    }
    used[v] = true;

    for(P pa : g[v]){
        int u = pa.first;
        if(u == p){
            continue;
        }
        if(used[u]){
            continue;
        }
        dfs2(u, v);
    }

    if(v == 0){
        return;
    }

    int cnt = 0;
    int ep;
    for(P pa : g[v]){
        int u = pa.first;
        int e = pa.second;
        if(u == p){
            ep = e;
        }
        if(d[e] == 1 && edge[e].first == v){
            cnt++;
        }
        if(d[e] == -1 && edge[e].second == v){
            cnt++;
        }
    }
    if(cnt % 2){
        if(edge[ep].first == v){
            d[ep] = 1;
        }else{
            d[ep] = -1;
        }
    }else{
        if(edge[ep].first == v){
            d[ep] = -1;
        }else{
            d[ep] = 1;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(m % 2){
        cout << -1 << endl;
        return 0;
    }

    g = initVec2<P>(n, 0);
    used = vector<bool>(n);
    edge = vector<P>(m);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        a--;
        b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
        edge[i] = {a, b};
    }

    d = vector<int>(m, INF);
    used = vector<bool>(n);
    dfs1(0, -1);
    rep(i, m){
        if(d[i] != 0){
            d[i] = 1;
        }
    }
    used = vector<bool>(n);
    dfs2(0, -1);

    rep(i, m){
        if(d[i] == 1){
            cout << edge[i].first + 1 << " " << edge[i].second + 1 << endl;
        }else{
            cout << edge[i].second + 1 << " " << edge[i].first + 1 << endl;
        }
    }

    return 0;
}
