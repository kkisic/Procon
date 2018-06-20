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

signed main(){
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }

        P st;
        vector<vector<bool>> area(m, vector<bool>(n, false));
        rep(i, m){
            rep(j, n){
                char c;
                cin >> c;

                if(c == '.'){
                    area[i][j] = true;
                }
                if(c == '@'){
                    area[i][j] = true;
                    st = make_pair(i, j);
                }
            }
        }

        vector<int> d = {0, 1, 0, -1};

        vector<vector<bool>> mark(m, vector<bool>(n, false));
        queue<P> que;
        que.push(st);
        int ans = 0;
        while(not que.empty()){
            P p = que.front();
            que.pop();

            int x = p.first;
            int y = p.second;
            if(mark[x][y] || not area[x][y]){
                continue;
            }

            mark[x][y] = true;
            ans++;
            rep(i, 4){
                int nx = x + d[i];
                int ny = y + d[i^1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n){
                    que.push(make_pair(nx, ny));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
