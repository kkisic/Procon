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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, m;
    cin >> n >> a >> b >> m;
    a--;
    b--;
    auto edge = initVec2<int>(n, 0);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    queue<P> que;
    vector<int> ans(n);
    vector<int> dep(n, INF);
    vector<bool> used(n, false);
    ans[a] = 1;
    dep[a] = 0;
    que.emplace(a, -1);
    while(not que.empty()){
        int v = que.front().first;
        int p = que.front().second;
        que.pop();

        if(used[v]){
            continue;
        }
        used[v] = true;

        for(int u : edge[v]){
            if(u == p){
                continue;
            }
            que.emplace(u, v);
            dep[u] = min(dep[u], dep[v] + 1);

            if(dep[u] > dep[v]){
                ans[u] += ans[v];
                ans[u] %= MOD;
            }
        }
    }
    cout << ans[b] << endl;

    return 0;
}
