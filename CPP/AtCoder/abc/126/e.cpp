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
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }

    int c = 0;
    vector<int> ans(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(ans[i] != -1){
            continue;
        }
        stack<P> st;
        st.emplace(i, 0);

        while(not st.empty()){
            int v = st.top().first;
            int per = st.top().second;
            st.pop();

            if(ans[v] != -1){
                continue;
            }
            ans[v] = c;

            for(int u : edge[v]){
                if(u == per){
                    continue;
                }
                st.emplace(u, v);
            }
        }
        c++;
    }
    cout << c << endl;

    return 0;
}
