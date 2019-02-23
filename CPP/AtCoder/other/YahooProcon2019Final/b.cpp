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

vector<int> dfs(vector2<int>& graph, int s){
    int n = graph.size();
    vector<int> depth(n, -1);

    stack<P> st;
    st.emplace(s, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;
        for(int u : graph[v]){
            st.emplace(u, d + 1);
        }
    }

    return depth;
}

pair<int, vector<int>> doubleSweep(vector2<int>& graph){
    int n = graph.size();
    vector<int> d1 = dfs(graph, 1);
    int f1 = 0;
    rep(i, n){
        if(d1[f1] < d1[i]){
            f1 = i;
        }
    }
    vector<int> d2 = dfs(graph, f1);
    int f2 = 0;
    rep(i, n){
        if(d2[f2] < d2[i]){
            f2 = i;
        }
    }
    vector<int> d3 = dfs(graph, f2);

    int dia = d2[f2];

    vector<int> len(n);
    for(int v = 1; v < n; v++){
        len[max(d2[v], d3[v])]++;
    }
    return make_pair(dia, len);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    auto graphA = initVec2<int>(n + 1, 0);
    rep(i, n - 1){
        int p, q;
        cin >> p >> q;
        graphA[p].push_back(q);
        graphA[q].push_back(p);
    }
    int m;
    cin >> m;
    auto graphB = initVec2<int>(m + 1, 0);
    rep(i, m - 1){
        int p, q;
        cin >> p >> q;
        graphB[p].push_back(q);
        graphB[q].push_back(p);
    }

    pair<int, vector<int>> dsA = doubleSweep(graphA);
    pair<int, vector<int>> dsB = doubleSweep(graphB);
    vector<int> lenA = dsA.second;
    vector<int> lenB = dsB.second;
    int maxD = max(dsA.first, dsB.first);

    vector<int> sumA(SZ(lenA) + 1);
    rep(i, SZ(lenA)){
        sumA[i+1] = sumA[i] + lenA[i];
    }
    vector<int> sumB(SZ(lenB) + 1);
    rep(i, SZ(lenB)){
        sumB[i+1] = sumB[i] + lenB[i];
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        if(maxD - i <= m){
            tmp = lenA[i] * (sumB[m] - sumB[maxD-i]);
        }
        ans += i * tmp;
        cnt += tmp;
    }
    for(int i = 0; i < m; i++){
        int tmp = 0;
        if(maxD - i <= n){
            tmp = lenB[i] * (sumA[n] - sumA[maxD-i]);
        }
        ans += i * tmp;
    }

    ans += (n * m - cnt) * maxD + cnt;
    cout << ans << endl;

    return 0;
}
