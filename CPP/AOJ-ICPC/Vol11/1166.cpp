#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

void solve(int w, int h){
    vector<vector<bool>> ud(h+1, vector<bool>(w, false));
    vector<vector<bool>> lr(h, vector<bool>(w+1, false));

    int x;
    rep(i, h-1){
        rep(j, w-1){
            cin >> x;
            if(x == 0){
                lr[i][j+1] = true;
            }
        }

        rep(j, w){
            cin >> x;
            if(x == 0){
                ud[i+1][j] = true;
            }
        }
    }
    rep(i, w-1){
        cin >> x;
        if(x == 0){
            lr[h-1][i+1] = true;
        }
    }

    queue<tuple<int, int, int>> que;
    que.emplace(0, 0, 1);
    vector<vector<int>> mark(h, vector<int>(w, 0));
    while(not que.empty()){
        tuple<int, int, int> p = que.front();
        que.pop();

        int x = get<0>(p);
        int y = get<1>(p);
        int d = get<2>(p);

        if(mark[x][y] != 0){
            continue;
        }

        mark[x][y] = d;

        if(ud[x][y]){
            que.emplace(x-1, y, d+1);
        }
        if(ud[x+1][y]){
            que.emplace(x+1, y, d+1);
        }
        if(lr[x][y]){
            que.emplace(x, y-1, d+1);
        }
        if(lr[x][y+1]){
            que.emplace(x, y+1, d+1);
        }
    }

    cout << mark[h-1][w-1] << endl;
}

signed main(){
    while(true){
        int w, h;
        cin >> w >> h;

        if(w == 0 && h == 0){
            break;
        }

        solve(w, h);
    }

    return 0;
}
