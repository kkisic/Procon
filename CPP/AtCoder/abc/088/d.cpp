#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

int h, w;

void bfs(const vector<vector<bool>>& a, vector<vector<int>>& r, queue<pair<P, int>>& q) {
    if(q.empty()){
        return;
    }
    pair<P, int> p = q.front();
    q.pop();
    int x = p.first.first;
    int y = p.first.second;
    if(r[x][y] != 0){
        bfs(a, r, q);
    }
    r[x][y] = p.second+1;

    if(x + 1 < h){
        if(a[x+1][y] && r[x+1][y] == 0){
            q.push(make_pair(make_pair(x+1, y), p.second+1));
        }
    }

    if(x - 1 >= 0){
        if(a[x-1][y] && r[x-1][y] == 0){
            q.push(make_pair(make_pair(x-1, y), p.second+1));
        }
    }

    if(y + 1 < w){
        if(a[x][y+1] && r[x][y+1] == 0){
            q.push(make_pair(make_pair(x, y+1), p.second+1));
        }
    }

    if(y - 1 >= 0){
        if(a[x][y-1] && r[x][y-1] == 0){
            q.push(make_pair(make_pair(x, y-1), p.second+1));
        }
    }
    bfs(a, r, q);
}


signed main(){
    cin >> h >> w;

    vector<vector<bool>> a(h, vector<bool>(w));
    vector<vector<int>> r(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            if(c == '.'){
                a[i][j] = true;
            }else{
                a[i][j] = false;
            }
        }
    }

    queue<pair<P, int>> q;
    r[0][0] = 1;
    if(a[0][1]){
        q.push(make_pair(make_pair(0, 1), 1));
    }
    if(a[1][0]){
        q.push(make_pair(make_pair(1, 0), 1));
    }
    bfs(a, r, q);

    if(r[h-1][w-1] == 0){
        cout << -1 << endl;
        return 0;
    }

    int black = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!a[i][j]){
                black++;
            }
        }
    }

    cout << h*w - r[h-1][w-1] - black << endl;

    return 0;
}
