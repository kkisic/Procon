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

pair<int, int> search(vector2<bool> &s, int n){
    rep(i, n) {
        rep(j, n){
            if(s[i][j]){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool isSame(vector2<bool> &s, vector2<bool> &t, int n, int offx, int offy){
    rep(i, n){
        rep(j, n){
            int ii = i + offx;
            int jj = j + offy;
            if(0 <= ii && ii < n && 0 <= jj && jj < n){
                if(s[i][j] != t[ii][jj]){
                    return false;
                }
            }else{
                if(s[i][j]) return false;
            }
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto s = initVec2<bool>(n, n);
    auto t = initVec3<bool>(4, n, n);
    int cs = 0, ct = 0;
    rep(i, n) rep(j, n) {
        char c;
        cin >> c;
        if(c == '#'){
            s[i][j] = true;
            cs++;
        }
    }
    rep(i, n) rep(j, n) {
        char c;
        cin >> c;
        if(c == '#'){
            t[0][i][j] = true;
            t[1][n-1-j][i] = true;
            t[2][n-1-i][n-1-j] = true;
            t[3][j][n-1-i] = true;
            ct++;
        }
    }

    if(cs != ct){
        cout << "No" << endl;
        return 0;
    }
    if(cs == 0){
        cout << "Yes" << endl;
        return 0;
    }

    rep(k, 4){
        auto p = search(s, n);
        int sx = p.first;
        int sy = p.second;
        p = search(t[k], n);
        int tx = p.first;
        int ty = p.second;

        if(isSame(s, t[k], n, tx - sx, ty - sy)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
