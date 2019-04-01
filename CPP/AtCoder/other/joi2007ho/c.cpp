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

bool check(int x, int y){
    return 0 <= x && x <= 5000 && 0 <= y && y <= 5000;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> vp(n);
    auto exist = initVec2<bool>(5001, 5001, false);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
        exist[x][y] = true;
    }

    int ans = 0;
    rep(i, n){
        for(int j = i + 1; j < n; j++){
            int vx = vp[i].first - vp[j].first;
            int vy = vp[i].second - vp[j].second;

            int x1 = vp[i].first + vy;
            int y1 = vp[i].second - vx;
            int x2 = vp[j].first + vy;
            int y2 = vp[j].second - vx;
            if(check(x1, y1) && check(x2, y2) && exist[x1][y1] && exist[x2][y2]){
                ans = max(ans, vx * vx + vy * vy);
            }

            x1 = vp[i].first - vy;
            y1 = vp[i].second + vx;
            x2 = vp[j].first - vy;
            y2 = vp[j].second + vx;
            if(check(x1, y1) && check(x2, y2) && exist[x1][y1] && exist[x2][y2]){
                ans = max(ans, vx * vx + vy * vy);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
