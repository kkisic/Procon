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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

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

typedef tuple<int, int, int, int> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<tup> vt(n);
    vector<int> x, y;
    x.push_back(0);
    x.push_back(w);
    y.push_back(0);
    y.push_back(h);
    rep(i, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vt[i] = {a, b, c, d};
        x.push_back(a);
        x.push_back(c);
        y.push_back(b);
        y.push_back(d);
    }
    sort(ALL(x));
    sort(ALL(y));
    UNIQUE(x);
    UNIQUE(y);

    int sx = SZ(x);
    int sy = SZ(y);
    map<int, int> enX, enY;
    rep(i, sx){
        enX[x[i]] = i;
    }
    rep(i, sy){
        enY[y[i]] = i;
    }

    auto area = initVec2<int>(sx + 1, sy + 1);
    rep(i, n){
        int a, b, c, d;
        tie(a, b, c, d) = vt[i];
        a = enX[a];
        b = enY[b];
        c = enX[c];
        d = enY[d];

        area[a][b] += 1;
        area[a][d] -= 1;
        area[c][b] -= 1;
        area[c][d] += 1;
    }

    rep(i, sx){
        rep(j, sy){
            area[i][j+1] += area[i][j];
        }
    }
    rep(j, sy){
        rep(i, sx){
            area[i+1][j] += area[i][j];
        }
    }

    bool used[4010][4010];
    int tt[4010][4010];
    rep(i, 4010) rep(j, 4010){
        used[i][j] = false;
        tt[i][j] = 0;
    }
    vector<int> d = {1, 0, -1, 0};
    int cnt = 0;
    for(int i = enX[0]; i < enX[w]; i++){
        for(int j = enY[0]; j < enY[h]; j++){
            if(area[i][j] > 0){
                continue;
            }
            if(used[i][j]){
                continue;
            }
            cnt++;
            stack<P> st;
            st.emplace(i, j);
            while(not st.empty()){
                int xx = st.top().first;
                int yy = st.top().second;
                st.pop();

                if(used[xx][yy]){
                    continue;
                }
                used[xx][yy] = true;
                tt[xx][yy] = cnt;

                rep(k, 4){
                    int nx = xx + d[k];
                    int ny = yy + d[k^1];
                    if(nx < enX[0] || enX[w] <= nx || ny < enY[0] || enY[h] <= ny){
                        continue;
                    }
                    if(area[nx][ny] > 0){
                        continue;
                    }
                    if(used[nx][ny]){
                        continue;
                    }
                    st.emplace(nx, ny);
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
