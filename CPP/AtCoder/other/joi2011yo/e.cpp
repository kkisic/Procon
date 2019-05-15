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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int h, w, n;
vector<int> vd = {1, 0, -1, 0};
vector<vector<bool>> a;

int dfs(P s, P t){
    auto dist = initVec2<int>(h, w, -1);
    queue<pair<P, int>> que;
    que.emplace(s, 0);

    while(not que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int d = que.front().second;
        que.pop();

        if(dist[x][y] != -1){
            continue;
        }
        dist[x][y] = d;

        rep(k, 4){
            int nx = x + vd[k];
            int ny = y + vd[k^1];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                continue;
            }
            if(dist[nx][ny] != -1){
                continue;
            }
            if(not a[nx][ny]){
                continue;
            }

            que.emplace(make_pair(nx, ny), d + 1);
        }
    }

    return dist[t.first][t.second];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n;
    a = initVec2<bool>(h, w, true);
    vector<P> pos(n + 1);
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == 'X'){
                a[i][j] = false;
                continue;
            }
            if(c == '.'){
                continue;
            }
            if(c == 'S'){
                pos[0] = {i, j};
                continue;
            }
            pos[c-'0'] = {i, j};
        }
    }

    int ans = 0;
    rep(i, n){
        ans += dfs(pos[i], pos[i+1]);
    }
    cout << ans << endl;

    return 0;
}
