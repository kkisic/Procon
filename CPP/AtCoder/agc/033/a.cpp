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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    auto a = initVec2<bool>(h, w, false);
    queue<pair<P, int>> q;
    rep(i, h) rep(j, w){
        char c;
        cin >> c;
        if(c == '#'){
            q.emplace(make_pair(i, j), 0);
        }
    }

    auto b = initVec2<int>(h, w, -1);
    vector<int> dd = {1, 0, -1, 0};
    while(not q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if(a[x][y]){
            continue;
        }
        a[x][y] = true;
        b[x][y] = d;

        rep(k, 4){
            int nx = x + dd[k];
            int ny = y + dd[k^1];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                continue;
            }
            if(a[nx][ny]){
                continue;
            }
            q.emplace(make_pair(nx, ny), d + 1);
        }
    }

    int ans = 0;
    rep(i, h){
        rep(j, w){
            ans = max(ans, b[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}
