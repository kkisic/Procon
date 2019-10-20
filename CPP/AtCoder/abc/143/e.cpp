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

    int n, m, l;
    cin >> n >> m >> l;

    auto edge = initVec2<int>(n, n, INF);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge[a][b] = c;
        edge[b][a] = c;
    }

    rep(k, n){
        rep(i, n){
            rep(j, n){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    rep(i, n){
        rep(j, n){
            if(edge[i][j] <= l){
                edge[i][j] = 1;
            }else{
                edge[i][j] = INF;
            }
        }
    }

    rep(k, n){
        rep(i, n){
            rep(j, n){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    rep(i, q){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        if(edge[s][t] == INF){
            cout << -1 << endl;
        }else{
            cout << edge[s][t] - 1 << endl;
        }
    }

    return 0;
}
