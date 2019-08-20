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

typedef tuple<int, int, int> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    auto edge = initVec2<int>(n + 1, 0);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> dep(n + 1, -1);
    vector<int> par(n + 1, 0);
    stack<tup> st;
    st.emplace(1, 1, 0);
    while(not st.empty()){
        int v, d, p;
        tie(v, d, p) = st.top();
        st.pop();
        if(dep[v] != -1){
            continue;
        }
        dep[v] = d;
        par[v] = p;
        for(int u : edge[v]){
            st.emplace(u, d + 1, v);
        }
    }

    int len = dep[n];
    int id = n;
    rep(i, len / 2){
        id = par[id];
    }

    vector<bool> used(n + 1, false);
    stack<int> sti;
    sti.push(n);
    while(not sti.empty()){
        int v = sti.top();
        sti.pop();

        if(used[v] || v == id){
            continue;
        }
        used[v] = true;
        for(int u : edge[v]){
            sti.push(u);
        }
    }

    int snuke = 0;
    rep(i, n + 1){
        if(used[i]){
            snuke++;
        }
    }

    int fennec = n - snuke;
    if(fennec > snuke){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }

    auto v = initVec3<int>(10, 10, 10, 0);

    return 0;
}
