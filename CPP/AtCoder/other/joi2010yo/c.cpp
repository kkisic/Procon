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
    auto edge = initVec2<int>(n + 1, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<bool> used(n + 1, false);
    queue<P> que;
    que.emplace(1, 0);

    while(not que.empty()){
        int v = que.front().first;
        int d = que.front().second;
        que.pop();

        if(d > 2){
            continue;
        }
        if(used[v]){
            continue;
        }
        used[v] = true;

        for(int u : edge[v]){
            if(used[u]){
                continue;
            }
            que.emplace(u, d + 1);
        }
    }

    int ans = 0;
    for(int v = 2; v <= n; v++){
        if(used[v]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
