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

    int n, K;
    cin >> n >> K;
    vector<int> x1(n), y1(n), d1(n), x2(n), y2(n), d2(n);
    rep(i, n) cin >> x1[i] >> y1[i] >> d1[i] >> x2[i] >> y2[i] >> d2[i];

    vector<int> x, y, d;
    rep(i, n){
        x.push_back(x1[i]);
        x.push_back(x2[i]);
        y.push_back(y1[i]);
        y.push_back(y2[i]);
        d.push_back(d1[i]);
        d.push_back(d2[i]);
    }
    sort(ALL(x));
    sort(ALL(y));
    sort(ALL(d));
    UNIQUE(x);
    UNIQUE(y);
    UNIQUE(d);

    int sx = SZ(x);
    int sy = SZ(y);
    int sd = SZ(d);
    map<int, int> enX, enY, enD;
    rep(i, sx){
        enX[x[i]] = i;
    }
    rep(i, sy){
        enY[y[i]] = i;
    }
    rep(i, sd){
        enD[d[i]] = i;
    }

    auto area = initVec3<int>(sx + 1, sy + 1, sd + 1);
    rep(i, n){
        area[enX[x1[i]]][enY[y1[i]]][enD[d1[i]]] += 1;
        area[enX[x2[i]]][enY[y1[i]]][enD[d1[i]]] -= 1;
        area[enX[x1[i]]][enY[y2[i]]][enD[d1[i]]] -= 1;
        area[enX[x1[i]]][enY[y1[i]]][enD[d2[i]]] -= 1;
        area[enX[x2[i]]][enY[y2[i]]][enD[d1[i]]] += 1;
        area[enX[x1[i]]][enY[y2[i]]][enD[d2[i]]] += 1;
        area[enX[x2[i]]][enY[y1[i]]][enD[d2[i]]] += 1;
        area[enX[x2[i]]][enY[y2[i]]][enD[d2[i]]] -= 1;
    }

    rep(i, sx) rep(j, sy) rep(k, sd){
        area[i][j][k+1] += area[i][j][k];
    }
    rep(i, sx) rep(k, sd) rep(j, sy){
        area[i][j+1][k] += area[i][j][k];
    }
    rep(j, sy) rep(k, sd) rep(i, sx){
        area[i+1][j][k] += area[i][j][k];
    }

    int ans = 0;
    rep(i, sx) rep(j, sy) rep(k, sd){
        if(area[i][j][k] < K){
            continue;
        }
        int s = i;
        while(area[s][j][k] >= K){
            s++;
        }
        int t = j;
        bool ok = true;
        while(t < sy && ok){
            t++;
            for(int m = i; m < s; m++){
                if(area[m][t][k] < K){
                    ok = false;
                }
            }
        }
        int u = k;
        ok = true;
        while(u < sd && ok){
            u++;
            for(int l = i; l < s; l++){
                for(int m = j; m < t; m++){
                    if(area[l][m][u] < K){
                        ok = false;
                    }
                }
            }
        }
        for(int X = i; X < s; X++){
            for(int Y = j; Y < t; Y++){
                for(int D = k; D < u; D++){
                    area[X][Y][D] = 0;
                }
            }
        }

        ans += (x[s] - x[i]) * (y[t] - y[j]) * (d[u] - d[k]);
    }
    cout << ans << endl;

    return 0;
}
