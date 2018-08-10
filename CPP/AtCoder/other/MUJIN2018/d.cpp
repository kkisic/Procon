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

int n, m;
vector<vector<int>> graph(1000 * 1000, vector<int>());

int rev(int x){
    int y = 0;

    while(x > 0){
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y;
}

void search(vector<vector<bool>>& able, int x, int y){
    vector<vector<bool>> mark(1000, vector<bool>(1000, false));

    stack<int> st;
    st.push(x * 1000 + y);

    while(not st.empty()){
        int p = st.top();
        st.pop();

        if(mark[p/1000][p%1000] || able[p/1000][p%1000]){
            continue;
        }
        mark[p/1000][p%1000] = true;
        if(p / 1000 <= n && p % 1000 <= m){
            able[p/1000][p%1000] = true;
        }

        for(int v : graph[p]){
            st.push(v);
        }
    }
}


signed main(){
    cin >> n >> m;

    rep(i, 1000){
        rep(j, 1000){
            int x = i < j ? rev(i) : rev(j);
            int y = i < j ? j : i;

            if(x < y){
                y = y - x;
            }else{
                x = x - y;
            }

            graph[x * 1000 + y].push_back(i * 1000 + j);
        }
    }

    vector<vector<bool>> mark(1000, vector<bool>(1000, false));
    rep(i, 1000){
        search(mark, 0, i);
        search(mark, i, 0);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(not mark[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
