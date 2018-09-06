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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> col(n+1);
    stack<P> st;
    st.emplace(1, 1);
    bool bipartite = true;
    while(not st.empty()){
        int v = st.top().first;
        int c = st.top().second;
        st.pop();

        if(col[v] != 0){
            if(col[v] != c){
                bipartite = false;
                break;
            }
            continue;
        }
        col[v] = c;

        for(int u : edge[v]){
            st.emplace(u, c * -1);
        }
    }

    int b = 0;
    int w = 0;
    rep(i, n){
        if(col[i+1] == 1){
            b++;
        }else{
            w++;
        }
    }

    if(bipartite){
        cout << b * w - m << endl;
    }else{
        cout << n * (n-1) / 2 - m << endl;
    }

    return 0;
}
