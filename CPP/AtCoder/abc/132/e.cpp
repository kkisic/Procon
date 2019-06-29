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

    int n, m;
    cin >> n >> m;

    auto edge = initVec2<int>(n * 3 + 1, 0);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v + n);
        edge[u + n].push_back(v + n * 2);
        edge[u + n * 2].push_back(v);
    }

    int s, t;
    cin >> s >> t;

    vector<int> used(n * 3 + 1, -1);
    queue<P> q;
    q.emplace(s, 0);
    while(not q.empty()){
        int v = q.front().first;
        int d = q.front().second;
        q.pop();
        if(used[v] != -1){
            continue;
        }
        used[v] = d;
        for(int u : edge[v]){
            if(used[u] != -1){
                continue;
            }
            q.emplace(u, d + 1);
        }
    }

    if(used[t] == -1){
        cout << -1 << endl;
    }else{
        cout << used[t] / 3 << endl;
    }

    return 0;
}
