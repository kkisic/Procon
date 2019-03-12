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

int n;
vector<int> a;
vector<vector<int>> edge;

int paint(vector<bool>& used, int v, int p, int color){
    used[v] = true;

    for(int u : edge[v]){
        if(u == p){
            continue;
        }
        if(used[u]){
            continue;
        }

        int c = paint(used, u, v, color);
        if(c == 0){
            continue;
        }
        if(c == -1){
            return -1;
        }
        if(a[v] == 0){
            if(c == color){
                a[v] = c;
            }
            continue;
        }
        if(a[v] != color && c == color){
            return -1;
        }
    }
    return a[v];
}

int solve(int v, int p){
    if(a[v] == 2){
        return 0;
    }

    int len = -1;
    for(int u : edge[v]){
        if(u == p){
            continue;
        }
        int tmp = solve(u, v);
        if(tmp == -1){
            continue;
        }
        if(a[u] != 1){
            tmp++;
        }
        len = tmp;
    }
    return len;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int r, b;
    a = vector<int>(n + 1);
    rep(i, n){
        cin >> a[i+1];
        if(a[i+1] == 1){
            r = i + 1;
        }
        if(a[i+1] == 2){
            b = i + 1;
        }
    }
    edge = initVec2<int>(n + 1, 0);
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<bool> used(n + 1, false);
    int res1 = paint(used, r, 0, 1);
    used = vector<bool>(n + 1, false);
    int res2 = paint(used, b, 0, 2);
    if(res1 == -1 || res2 == -1){
        cout << 0 << endl;
        return 0;
    }

    cout << solve(r, 0) << endl;

    return 0;
}
