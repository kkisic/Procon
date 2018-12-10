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

int best = 0;
vector<int> w;

int dfs(vector<vector<P>>& edge, int par, int v, int ww){
    int cost = 0;
    int tmp = 0;

    best = max(best, w[v]);

    vector<int> res;
    for(P p : edge[v]){
        if(p.first == par){
            continue;
        }
        res.push_back(dfs(edge, v, p.first, p.second));
    }
    sort(ALL(res), greater<int>());

    if(SZ(res) >= 2){
        tmp = res[0] + res[1] +  w[v];
        best = max(best, tmp);
    }

    if(SZ(res) >= 1){
        if(res[0] > 0){
            cost += res[0];
        }
        best = max(best, res[0] + w[v]);
    }

    cost += w[v] - ww;
    return cost;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    w = vector<int>(n+1);
    rep(i, n) cin >> w[i+1];
    vector<vector<P>> edge(n+1, vector<P>());
    rep(i, n - 1){
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].emplace_back(v, c);
        edge[v].emplace_back(u, c);
    }

    dfs(edge, 0, 1, 0);
    cout << best << endl;

    return 0;
}
