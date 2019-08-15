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
vector<bool> exist;
vector2<int> edge;

int dfs(int v, int p){
    int child = 0;
    for(int u : edge[v]){
        if(u == p){
            continue;
        }
        int tmp = dfs(u, v);
        if(tmp >= 2 && exist[v]){
            return INF;
        }
        child += tmp;
    }

    if(child == 0 && exist[v]){
        child = 1;
    }
    return child;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    exist = vector<bool>(n, false);
    edge = initVec2<int>(n, 0);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    rep(i, m){
        int x;
        cin >> x;
        exist[x-1] = true;
    }

    int ans = dfs(0, -1);

    if(ans <= 2){
        cout << "Yes" << endl;
    }else{
        cout << "trumpet" << endl;
    }

    return 0;
}
