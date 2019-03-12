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

int n, m;
vector<int> ans;
vector<bool> used;
vector<vector<int>> graph;

int solve(int v, int p){
    vector<int> c;
    used[v] = true;

    for(int u : graph[v]){
        if(u == p){
            continue;
        }
        if(used[u]){
            continue;
        }
        int x = solve(u, v);
        if(x != -1){
            c.push_back(u);
        }
    }

    if(SZ(c) == 0){
        if(v == 1){
            int u = graph[v][0];
            ans[v] = ans[u];
            ans[u] = v;
        }
        return v;
    }

    c.push_back(v);
    rep(i, SZ(c)){
        ans[c[i]] = c[(i+1)%SZ(c)];
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    graph = initVec2<int>(n + 1, 0);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = vector<int>(n + 1);
    used = vector<bool>(n + 1, false);
    solve(1, 0);

    rep(i, n){
        cout << ans[i+1] << " ";
    }
    cout << endl;

    return 0;
}
