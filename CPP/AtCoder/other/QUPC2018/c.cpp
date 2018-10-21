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
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<bool>> area(h, vector<bool>(w, false));
    P s, g;
    vector<P> ino;
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == '#'){
                continue;
            }
            if(c == '@'){
                ino.emplace_back(i, j);
                continue;
            }
            if(c == 'S'){
                s = make_pair(i, j);
            }
            if(c == 'G'){
                g = make_pair(i, j);
            }
            area[i][j] = true;
        }
    }

    queue<pair<P, int>> que;
    for(P p : ino){
        que.emplace(p, 0);
    }

    vector<int> dd = {1, 0, -1, 0};
    vector<vector<int>> dep(h, vector<int>(w, INF));
    while(not que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int d = que.front().second;
        que.pop();

        if(dep[x][y] != INF && dep[x][y] < d){
            continue;
        }
        dep[x][y] = d;
        if(d == k){
            continue;
        }

        rep(i, 4){
            int nx = x + dd[i];
            int ny = y + dd[i^1];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && area[nx][ny] && (dep[nx][ny] == INF || dep[nx][ny] > d + 1)){
                que.emplace(make_pair(nx, ny), d+1);
                area[nx][ny] = false;
            }
        }
    }

    vector<vector<bool>> marked(h, vector<bool>(w, false));
    que.emplace(s, 0);
    while(not que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int d = que.front().second;
        que.pop();

        if(x == g.first && y == g.second){
            cout << d << endl;
            return 0;
        }

        if(marked[x][y]){
            continue;
        }
        marked[x][y] = true;

        rep(i, 4){
            int nx = x + dd[i];
            int ny = y + dd[i^1];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && area[nx][ny]){
                que.emplace(make_pair(nx, ny), d+1);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
