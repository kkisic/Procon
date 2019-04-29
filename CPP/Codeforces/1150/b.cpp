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
    rep(i, n) rep(j, n){
        char c;
        cin >> c;
        if(c == '#'){
            a[i][j] = true;
        }
    }

    vector<int> s = {-1, 0, 1, 0};
    vector<int> t = {1, 1, 1, 2};
    rep(j, n - 2){
        for(int i = 1; i < n - 1; i++){
            if(a[i][j]){
                continue;
            }
            a[i][j] = true;
            rep(k, 4){
                int x = i + s[k];
                int y = j + t[k];
                if(a[x][y]){
                    cout << "NO" << endl;
                    return 0;
                }
                a[x][y] = true;
            }
        }
    }

    rep(i, n){
        rep(j, n){
            if(not a[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}
