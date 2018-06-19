#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int find(int v, vector<int>& p){
    if(p[v] == -1){
        return v;
    }
    p[v] = find(p[v], p);
    return p[v];
}

void unite(int u, int v, vector<int>& p){
    int u_root = find(u, p);
    int v_root = find(v, p);

    if(u_root == v_root){
        return;
    }
    p[u_root] = v_root;
}

signed main(){
    int w, h;
    cin >> w >> h;
    vector<tuple<int, int, int>> edge;
    rep(i, w){
        int p;
        cin >> p;
        edge.emplace_back(p, i, 0);
    }
    rep(i, h){
        int q;
        cin >> q;
        edge.emplace_back(q, i, 1);
    }
    sort(edge.begin(), edge.end());

    vector<int> parent(w + h + 2, -1);
    int ans = 0;
    int a = w+1;
    int b = h+1;
    rep(i, w+h){
        if(get<2>(edge[i]) == 0){
            int ww = get<1>(edge[i]);
            int u = find(ww, parent);
            int v = find(ww+1, parent);

            unite(u, v, parent);
            ans += get<0>(edge[i]) * b;
            a--;
        }else{
            int hh = get<1>(edge[i]);
            int u = find(w+1 + hh, parent);
            int v = find(w+1 + hh+1, parent);

            unite(u, v, parent);
            ans += get<0>(edge[i]) * a;
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}
