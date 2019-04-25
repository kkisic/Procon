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

void dfs(int u, vector<vector<int>>& edge, vector<int>& trail){
    while(!edge[u].empty()){
        int v = edge[u].back();
        edge[u].pop_back();
        for(int i = 0; i < (int)edge[v].size(); i++){
            if(edge[v][i] == u){
                edge[v].erase(edge[v].begin() + i);
                break;
            }
        }
        dfs(v, edge, trail);
    }
    trail.push_back(u);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> b(n-1), c(n-1);
    rep(i, n - 1) cin >> b[i];
    rep(i, n - 1) cin >> c[i];

    set<int> s;
    rep(i, n - 1){
        if(b[i] > c[i]){
            cout << -1 << endl;
            return 0;
        }
        s.insert(b[i]);
        s.insert(c[i]);
    }

    int m = 0;
    vector<int> decode;
    map<int, int> encode;
    for(auto it = s.begin(); it != s.end(); it++){
        decode.push_back(*it);
        encode[*it] = m++;
    }

    auto edge = initVec2<int>(m, 0);
    rep(i, n - 1){
        int u = encode[b[i]];
        int v = encode[c[i]];
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int odd = 0;
    int st = -1;
    rep(i, m){
        if(SZ(edge[i]) % 2){
            odd++;
            st = i;
        }
    }

    if(odd > 2){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    dfs((st == -1 ? 0 : st), edge, ans);

    if(SZ(ans) != n){
        cout << -1 << endl;
        return 0;
    }

    rep(i, SZ(ans)){
        cout << decode[ans[i]] << " ";
    }
    cout << endl;

    return 0;
}
