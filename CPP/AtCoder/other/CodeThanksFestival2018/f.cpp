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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, n){
        int p;
        cin >> p;
        edge[p].push_back(i+1);
    }

    vector<int> dep(n+1);
    stack<P> st;
    st.emplace(0, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();
        dep[v] = d;
        for(int u : edge[v]){
            st.emplace(u, d+1);
        }
    }

    vector<int> used(n+1, false);
    vector<int> ans(m);
    rep(i, m){
        for(int j = 1; j <= n; j++){
            if(used[j] || k < dep[j]){
                continue;
            }
            used[j] = true;

            vector<int> dd(n+1);
            stack<int> st;
            st.push(0);
            while(not st.empty()){
                int v = st.top();
                st.pop();

                if(used[v]){
                    continue;
                }
                dd[dep[v]]++;
                for(int u : edge[v]){
                    st.push(u);
                }
            }

            int mini = 0;
            int cnt = m - i - 1;
            for(int l = 1; l <= n; l++){
                int tmp = min(cnt, dd[l]);
                mini += l * tmp;
                cnt -= tmp;
            }
            if(cnt != 0){
                used[j] = false;
                continue;
            }

            int maxi = 0;
            cnt = m - i - 1;
            for(int l = n; l > 0; l--){
                int tmp = min(cnt, dd[l]);
                maxi += l * tmp;
                cnt -= tmp;
            }
            if(cnt != 0){
                used[j] = false;
                continue;
            }

            if(mini <= k - dep[j] && k - dep[j] <= maxi){
                ans[i] = j;
                k -= dep[j];

                st = stack<int>();
                st.push(j);
                while(not st.empty()){
                    int v = st.top();
                    st.pop();
                    used[v] = true;

                    for(int u : edge[v]){
                        st.push(u);
                    }
                }
                break;
            }
            used[j] = false;
        }
        if(ans[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i, m - 1){
        cout << ans[i] << " ";
    }
    cout << ans[m-1] << endl;

    return 0;
}
