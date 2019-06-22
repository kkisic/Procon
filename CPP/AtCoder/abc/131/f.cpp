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

vector2<int> ver, hor;
vector<int> usedV, usedH;

P dfs2(int v);

P dfs1(int v){
    if(usedH[v]){
        return {0, 0};
    }
    usedH[v] = true;
    P ret= {1, 0};
    for(int u : hor[v]){
        if(usedV[u]){
            continue;
        }
        P tmp = dfs2(u);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}
P dfs2(int v){
    if(usedV[v]){
        return {0, 0};
    }
    usedV[v] = true;
    P ret = {0, 1};
    for(int u : ver[v]){
        if(usedH[u]){
            continue;
        }
        P tmp = dfs1(u);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> vp(n);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }

    ver = initVec2<int>(100001, 0);
    hor = initVec2<int>(100001, 0);
    rep(i, n){
        ver[vp[i].second].push_back(vp[i].first);
        hor[vp[i].first].push_back(vp[i].second);
    }

    usedV = vector<int>(100001, false);
    usedH = vector<int>(100001, false);

    int ans = 0;
    rep(i, n){
        P p = {0, 0};
        P tmp;
        tmp = dfs1(vp[i].first);
        p.first += tmp.first;
        p.second += tmp.second;
        tmp = dfs2(vp[i].second);
        p.first += tmp.first;
        p.second += tmp.second;

        ans += p.first * p.second;
    }

    cout << ans - n << endl;

    return 0;
}
