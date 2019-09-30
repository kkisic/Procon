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
    cin >> n;
    auto a = initVec2<bool>(n, n, false);
    auto b = initVec2<bool>(n, n, false);
    rep(i, n) rep(j, n){
        char x;
        cin >> x;
        if(x == '1'){
            a[i][j] = true;
        }
    }
    rep(i, n) rep(j, n){
        char x;
        cin >> x;
        if(x == '1'){
            b[i][j] = true;
        }
    }

    auto c = initVec2<bool>(n, n, true);
    rep(i, n){
        rep(j, n){
            if(b[i][j]){
                continue;
            }
            rep(k, n){
                if(not a[i][k]){
                    continue;
                }
                c[k][j] = false;
            }
        }
    }

    auto bb = initVec2<bool>(n, n, false);
    rep(i, n){
        rep(k, n){
            if(not a[i][k]){
                continue;
            }
            rep(j, n){
                if(c[k][j]){
                    bb[i][j] = true;
                }
            }
        }
    }

    rep(i, n){
        rep(j, n){
            if(b[i][j] != bb[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    rep(i, n){
        rep(j, n){
            cout << c[i][j];
        }
        cout << endl;
    }

    return 0;
}
