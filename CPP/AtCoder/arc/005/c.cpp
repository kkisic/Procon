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

int h, w;

signed main(){
    cin >> h >> w;
    P s, g;

    vector<vector<char>> c(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> c[i][j];

            if(c[i][j] == 's'){
                s = make_pair(i, j);
            }
            if(c[i][j] == 'g'){
                g = make_pair(i, j);
            }
        }
    }

    vector<vector<vector<bool>>> vis(h, vector<vector<bool>>(w, vector<bool>(3, false)));
    queue<pair<P, int>> q;
    q.emplace(s, 2);

    while(not q.empty()){
        pair<P, int> p = q.front();
        q.pop();

        if(p.first == g){
            cout << "YES" << endl;
            return 0;
        }

        int x = p.first.first;
        int y = p.first.second;
        int d = p.second;

        if(x + 1 < h){
            if(c[x+1][y] != '#' && not vis[x+1][y][d]){
                vis[x+1][y][d] = true;
                q.emplace(make_pair(x+1, y), d);
            }else if(d > 0 && not vis[x+1][y][d-1]){
                vis[x+1][y][d-1] = true;
                q.emplace(make_pair(x+1, y), d-1);
            }
        }
        if(x - 1 >= 0){
            if(c[x-1][y] != '#' && not vis[x-1][y][d]){
                vis[x-1][y][d] = true;
                q.emplace(make_pair(x-1, y), d);
            }else if(d > 0 && not vis[x-1][y][d-1]){
                vis[x-1][y][d-1] = true;
                q.emplace(make_pair(x-1, y), d-1);
            }
        }
        if(y + 1 < w){
            if(c[x][y+1] != '#' && not vis[x][y+1][d]){
                vis[x][y+1][d] = true;
                q.emplace(make_pair(x, y+1), d);
            }else if(d > 0 && not vis[x][y+1][d-1]){
                vis[x][y+1][d-1] = true;
                q.emplace(make_pair(x, y+1), d-1);
            }
        }
        if(y - 1 >= 0){
            if(c[x][y-1] != '#' && not vis[x][y-1][d]){
                vis[x][y-1][d] = true;
                q.emplace(make_pair(x, y-1), d);
            }else if(d > 0 && not vis[x][y-1][d-1]){
                vis[x][y-1][d-1] = true;
                q.emplace(make_pair(x, y-1), d-1);
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
