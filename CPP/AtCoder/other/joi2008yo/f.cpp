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

    int n, k;
    cin >> n >> k;

    auto dist = initVec2<int>(n + 1, n + 1, INF);
    for(int v = 1; v <= n; v++){
        dist[v][v] = 0;
    }

    rep(i, k){
        int q;
        cin >> q;

        if(q){
            int c, d, e;
            cin >> c >> d >> e;
            dist[c][d] = min(dist[c][d], e);
            dist[d][c] = min(dist[d][c], e);

            for(int v = 1; v <= n; v++){
                for(int u = 1; u <= n; u++){
                    dist[v][u] = min(dist[v][u], dist[v][c] + dist[c][d] + dist[d][u]);
                    dist[v][u] = min(dist[v][u], dist[v][d] + dist[d][c] + dist[c][u]);
                }
            }
        }else{
            int a, b;
            cin >> a >> b;
            cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
        }
    }

    return 0;
}
