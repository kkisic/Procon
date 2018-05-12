#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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
    int n, m;
    cin >> n >> m;

    vector<int> p(n+1);
    rep(i, n) cin >> p[i+1];

    vector<int> x(m), y(m);
    rep(i, m){
        cin >> x[i] >> y[i];
    }

    vector<int> parent(n+1, -1);

    rep(i, m){
        unite(x[i], y[i], parent);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a = find(i, parent);
        int b = find(p[i], parent);
        if(a == b){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
