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

    int h, w;
    cin >> h >> w;
    vector<vector<bool>> edge(h, vector<bool>(w, false));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == '#'){
                edge[i][j] = true;
            }
        }
    }

    vector<vector<int>> mark(h, vector<int>(w));
    vector<int> d = {1, 0, -1, 0};
    int color = 0;
    rep(i, h){
        rep(j, w){
            if(mark[i][j] != 0){
                continue;
            }
            stack<pair<P, int>> st;
            st.emplace(make_pair(i, j), ++color);

            while(not st.empty()){
                int x = st.top().first.first;
                int y = st.top().first.second;
                int c = st.top().second;
                st.pop();

                if(mark[x][y] != 0){
                    continue;
                }
                mark[x][y] = c;

                rep(k, 4){
                    int nx = x + d[k];
                    int ny = y + d[k^1];

                    if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                        continue;
                    }
                    if(edge[x][y] == not edge[nx][ny]){
                        st.emplace(make_pair(nx, ny), -c);
                    }
                }
            }
        }
    }

    map<int, int> m;
    rep(i, h){
        rep(j, w){
            if(m.find(mark[i][j]) == m.end()){
                m[mark[i][j]] = 0;
            }
            m[mark[i][j]]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= color; i++){
        ans += m[i] * m[-i];
    }
    cout << ans << endl;

    return 0;
}
