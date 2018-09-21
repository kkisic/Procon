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
    int n;
    cin >> n;

    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, n){
        int a;
        cin >> a;

        edge[i+1].push_back(a);
        edge[a].push_back(i+1);
    }

    vector<int> mark(n+1);
    rep(i, n){
        if(mark[i+1] != 0){
            continue;
        }

        stack<P> st;
        st.emplace(i+1, i+1);

        while(not st.empty()){
            int v = st.top().first;
            int c = st.top().second;
            st.pop();

            if(mark[v] != 0){
                if(mark[v] != c){
                    cout << -1 << endl;
                    return 0;
                }
                continue;
            }
            mark[v] = c;

            for(int u: edge[v]){
                st.emplace(u, c * -1);
            }
        }
    }

    map<int, int> m;
    rep(i, n){
        if(m.find(mark[i+1]) == m.end()){
            m.emplace(mark[i+1], 0);
            m.emplace(mark[i+1] * -1, 0);
        }
        m[mark[i+1]]++;
    }

    int ans = 0;
    rep(i, n){
        ans += max(m[i+1], m[(i+1) * -1]);
    }
    cout << ans << endl;

    return 0;
}
