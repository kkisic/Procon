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

signed main(){
    while(true){
        int w, h;
        cin >> w >> h;

        if(w == 0 && h == 0){
            break;
        }

        vector<vector<bool>> area(h, vector<bool>(w, false));
        rep(i, h){
            rep(j, w){
                int x;
                cin >> x;
                if(x == 1){
                    area[i][j] = true;
                }
            }
        }

        vector<vector<int>> mark(h, vector<int>(w, 0));
        int c = 1;

        vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
        vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

        rep(i, h){
            rep(j, w){
                if(mark[i][j] != 0 || not area[i][j]){
                    continue;
                }

                stack<P> st;
                st.emplace(i, j);

                while(not st.empty()){
                    P p = st.top();
                    st.pop();

                    int x = p.first;
                    int y = p.second;

                    if(mark[x][y] != 0 || not area[i][j]){
                        continue;
                    }

                    mark[x][y] = c;

                    rep(k, 8){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(0 <= nx && nx < h && 0 <= ny && ny < w && area[nx][ny]){
                            st.emplace(nx, ny);
                        }
                    }
                }
                c++;
            }
        }
        cout << c - 1 << endl;
    }

    return 0;
}
