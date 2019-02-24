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

    int n;
    int r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    auto a = initVec2<bool>(n, n, false);
    rep(i, n){
        rep(j, n){
            char c;
            cin >> c;
            if(c == '0'){
                a[i][j] = true;
            }
        }
    }

    vector<int> d = {1, 0, -1, 0};
    auto d1 = initVec2<int>(n, n, -1);
    queue<pair<P, int>> que;
    que.emplace(make_pair(r1, c1), 0);
    while(not que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int dist = que.front().second;
        que.pop();

        if(d1[x][y] != -1){
            continue;
        }
        if(not a[x][y]){
            continue;
        }
        d1[x][y] = dist;
        rep(i, 4){
            int nx = x + d[i];
            int ny = y + d[i^1];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny]){
                que.emplace(make_pair(nx, ny), dist + 1);
            }
        }
    }
    auto d2 = initVec2<int>(n, n, -1);
    que = queue<pair<P, int>>();
    que.emplace(make_pair(r2, c2), 0);
    while(not que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int dist = que.front().second;
        que.pop();

        if(d2[x][y] != -1){
            continue;
        }
        if(not a[x][y]){
            continue;
        }
        d2[x][y] = dist;
        rep(i, 4){
            int nx = x + d[i];
            int ny = y + d[i^1];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny]){
                que.emplace(make_pair(nx, ny), dist + 1);
            }
        }
    }

    if(d1[r2][c2] != -1){
        cout << 0 << endl;
        return 0;
    }

    int ans = INF;
    rep(i, n){
        rep(j, n){
            if(d1[i][j] == -1){
                continue;
            }
            rep(k, n){
                rep(l, n){
                    if(d2[k][l] == -1){
                        continue;
                    }
                    int tmp = (i - k) * (i - k) + (j - l) * (j - l);
                    ans = min(ans, tmp);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
