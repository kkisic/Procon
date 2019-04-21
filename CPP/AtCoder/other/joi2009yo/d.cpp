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

int n, m;
vector<int> d = {1, 0, -1, 0};

int search(vector2<bool>& a, int x, int y, int cnt){
    a[x][y] = false;

    int res = cnt;
    rep(k, 4){
        int nx = x + d[k];
        int ny = y + d[k^1];
        if(nx < 0 || n <= nx || ny < 0 || m <= ny){
            continue;
        }
        if(not a[nx][ny]){
            continue;
        }
        res = max(res, search(a, nx, ny, cnt + 1));
    }

    a[x][y] = true;
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    auto a = initVec2<bool>(n, m, false);
    rep(i, n) rep(j, m){
        int x;
        cin >> x;
        if(x == 1){
            a[i][j] = true;
        }
    }

    int ans = 0;
    rep(i, n){
        rep(j, m){
            if(not a[i][j]){
                continue;
            }
            ans = max(ans, search(a, i, j, 1));
        }
    }
    cout << ans << endl;

    return 0;
}
