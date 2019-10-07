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
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    auto a = initVec2<int>(h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];

    auto edge = initVec2<int>(h * w, 0);
    vector<int> d = {1, 0, -1, 0};
    rep(i, h) rep(j, w){
        int s = i;
        int t = j;
        rep(k, 4){
            int nx = i + d[k];
            int ny = j + d[k^1];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                continue;
            }

            if(a[s][t] > a[nx][ny]){
                s = nx;
                t = ny;
            }
        }
        if(s == i && t == j){
            continue;
        }
        edge[i*w+j].push_back(s*w+t);
    }

    auto ans = initVec2<char>(h, w, '.');
    stack<int> st;
    st.push(x*w+y);
    while(not st.empty()){
        int v = st.top();
        st.pop();
        ans[v/w][v%w] = 'W';

        for(int u : edge[v]){
            st.push(u);
        }
    }

    rep(i, h){
        rep(j, w){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
