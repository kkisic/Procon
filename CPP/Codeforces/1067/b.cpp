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

template <typename T>
void debugv(vector<T>& vec){
    for(T t : vec){
        cout << t << endl;
    }
    cout << endl;
}

int dfs(const vector<vector<int>>& edge, int s, vector<int>& depth){
    int n = edge.size();
    stack<P> st;
    st.emplace(s, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;

        for(int u : edge[v]){
            st.emplace(u, d+1);
        }
    }

    int ans = s;
    rep(i, n){
        if(depth[i] > depth[ans]){
            ans = i;
        }
    }

    return ans;
}

bool bfs(const vector<vector<int>>& edge, int s, int k){
    int n = edge.size();
    vector<int> depth(n+1, -1);
    queue<P> que;
    que.emplace(s, k);
    while(not que.empty()){
        int v = que.front().first;
        int d = que.front().second;
        que.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;

        int cnt = 0;
        for(int u : edge[v]){
            if(depth[u] != -1){
                continue;
            }
            que.emplace(u, d-1);
            cnt++;
        }

        if(d != 0 && cnt < 3){
            return false;
        }
    }

    return true;
}

signed main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> depth1(n+1, -1);
    int far1 = dfs(edge, 1, depth1);

    vector<int> depth2(n+1, -1);
    int far2 = dfs(edge, far1, depth2);

    vector<int> depth3(n+1, -1);
    int far3 = dfs(edge, far2, depth3);

    int dia = depth2[far2];
    if(dia % 2 != 0 || dia / 2 != k){
        cout << "No" << endl;
        return 0;
    }

    set<int> c1, c2;
    rep(i, n+1){
        if(depth2[i] == k){
            c1.insert(i);
        }
        if(depth3[i] == k){
            c2.insert(i);
        }
    }

    int center = -1;
    for(int v : c1){
        for(int u : c2){
            if(v == u){
                center = v;
            }
        }
    }
    if(center == -1){
        cout << "No" << endl;
    }

    if(bfs(edge, center, k)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
