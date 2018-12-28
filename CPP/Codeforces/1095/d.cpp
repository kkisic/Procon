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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> edge(n + 1, vector<int>());
    int v1, v2;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        if(i == 0){
            v1 = a;
            v2 = b;
        }
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> ans;
    stack<P> st;
    st.emplace(0, 1);
    vector<bool> mark(n+1, false);
    while(not st.empty()){
        int par = st.top().first;
        int v = st.top().second;
        st.pop();

        if(mark[v]){
            continue;
        }
        mark[v] = true;
        ans.push_back(v);

        for(int u : edge[v]){
            if(u != par){
                if(v == 1){
                    if(u != v1 && u != v2){
                        continue;
                    }
                }
                st.emplace(v, u);
                break;
            }
        }
    }

    rep(i, n - 1){
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;

    return 0;
}
