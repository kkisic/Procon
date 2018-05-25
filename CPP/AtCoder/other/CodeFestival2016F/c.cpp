#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

    vector<int> parent(n+m, -1);
    rep(i, n){
        int k;
        cin >> k;
        rep(j, k){
            int l;
            cin >> l;
            unite(i, n+l-1, parent);
        }
    }

    set<int> kind;
    rep(i, n){
        kind.insert(find(i, parent));
    }
    if(kind.size() == 1){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}
