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

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<vector<int>> edge(n, vector<int>());
    rep(i, m){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    if(m == n - 1){
        cout << 0 << endl;
        return 0;
    }

    if(n < 2 * (n - m - 1)){
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> mark(n, -1);
    rep(i, n){
        if(mark[i] != -1){
            continue;
        }
        stack<int> st;
        st.push(i);

        while(not st.empty()){
            int v = st.top();
            st.pop();

            if(mark[v] != -1){
                continue;
            }
            mark[v] = i;

            for(int u : edge[v]){
                if(mark[u] == -1){
                    st.push(u);
                }
            }
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> used(n, false);
    rep(i, n){
        pq.emplace(a[i], mark[i]);
    }

    int ans = 0;
    int remain = 2 * (n - m - 1) - (n - m);
    rep(i, n){
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(not used[v]){
            used[v] = true;
            ans += cost;
            continue;
        }

        if(remain > 0){
            ans += cost;
            remain--;
        }
    }
    cout << ans << endl;

    return 0;
}
