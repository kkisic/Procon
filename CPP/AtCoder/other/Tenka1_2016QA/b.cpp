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

vector<int> need;

int dfs(const vector<vector<int>>& edge, int v){
    if(need[v] > 0){
        return need[v];
    }

    int mini = INF;
    for(int u : edge[v]){
        mini = min(mini, dfs(edge, u));
    }
    need[v] = mini;

    return mini;
}

int dfs2(const vector<vector<int>>& edge, int v){
    int cost = 0;
    for(int u : edge[v]){
        cost += dfs2(edge, u);
        cost += need[u] - need[v];
    }
    return cost;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n, vector<int>());
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        edge[p].push_back(i);
    }

    need = vector<int>(n + 1);
    rep(i, m){
        int b, c;
        cin >> b >> c;
        need[b] = c;
    }

    dfs(edge, 0);
    need[0] = 0;
    cout << dfs2(edge, 0) << endl;

    return 0;
}
