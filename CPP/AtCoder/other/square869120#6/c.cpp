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
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == '.'){
                a[i][j] = true;
            }
        }
    }

    vector<bool> path(h, true);
    rep(i, h){
        rep(j, w){
            if(not a[i][j]){
                path[i] = false;
            }
        }
    }

    auto used1 = initVec2<bool>(h, w, false);
    vector<int> d1 = {1, 0};
    stack<P> st;

    st.emplace(0, 0);
    while(not st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        st.pop();

        if(used1[x][y]){
            continue;
        }
        used1[x][y] = true;
        rep(k, 4){
            int nx = x + d1[k];
            int ny = y + d1[k^1];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                continue;
            }
            if(used1[nx][ny]){
                continue;
            }
            if(not a[nx][ny]){
                continue;
            }
            st.emplace(nx, ny);
        }
    }

    auto used2 = initVec2<bool>(h, w, false);
    vector<int> d2 = {-1, 0};

    st.emplace(h - 1, w - 1);
    while(not st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        st.pop();

        if(used2[x][y]){
            continue;
        }
        used2[x][y] = true;
        rep(k, 4){
            int nx = x + d2[k];
            int ny = y + d2[k^1];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                continue;
            }
            if(used2[nx][ny]){
                continue;
            }
            if(not a[nx][ny]){
                continue;
            }
            st.emplace(nx, ny);
        }
    }

    bool ok = false;
    rep(i, h){
        if(not path[i]){
            continue;
        }

        bool s = false;
        bool t = false;
        rep(j, w){
            if(used1[i][j]){
                s = true;
            }
            if(used2[i][j]){
                t = true;
            }
        }
        if(s && t){
            ok = true;
        }
    }

    cout << (ok ? "Yay!" : ":(") << endl;

    return 0;
}
