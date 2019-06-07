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
    cin >> w >> h;
    auto a = initVec2<bool>(h + 2, w + 2, true);
    rep(i, h) rep(j, w){
        int x;
        cin >> x;
        if(x){
            a[i+1][j+1] = false;
        }
    }

    vector<int> dx = {1, 1, 0, -1, -1, 0};
    vector<vector<int>> dy(2);
    dy[0] = {-1, 0, 1, 0, -1, -1};
    dy[1] = {0, 1, 1, 1, 0, -1};

    auto used = initVec2<bool>(h + 2, w + 2, false);
    stack<P> st;
    st.emplace(0, 0);
    while(not st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        st.pop();

        if(used[x][y]){
            continue;
        }
        used[x][y] = true;

        rep(k, 6){
            int nx = x + dx[k];
            int ny = y + dy[x%2][k];

            if(nx < 0 || h + 2 <= nx || ny < 0 || w + 2 <= ny){
                continue;
            }
            if(used[nx][ny]){
                continue;
            }
            if(not a[nx][ny]){
                continue;
            }
            st.emplace(nx, ny);
        }
    }

    int ans = 0;
    rep(i, h + 2){
        rep(j, w + 2){
            if(not used[i][j]){
                continue;
            }
            rep(k, 6){
                int nx = i + dx[k];
                int ny = j + dy[i%2][k];

                if(nx < 0 || h + 2 <= nx || ny < 0 || w + 2 <= ny){
                    continue;
                }
                if(not a[nx][ny]){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
