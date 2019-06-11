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
    rep(i, h) rep(j, w){
        char c;
        cin >> c;
        if(c == '*'){
            a[i][j] = true;
        }
    }

    if(h <= 2 || w <= 2){
        cout << "NO" << endl;
        return 0;
    }

    bool ok = false;
    for(int i = 1; i < h - 1; i++){
        for(int j = 1; j < w - 1; j++){
            if(a[i][j] && a[i-1][j] && a[i+1][j] && a[i][j-1] && a[i][j+1]){
                a[i][j] = false;
                int k = i + 1;
                while(k < h && a[k][j]){
                    a[k][j] = false;
                    k++;
                }
                k = i - 1;
                while(k >= 0 && a[k][j]){
                    a[k][j] = false;
                    k--;
                }
                k = j + 1;
                while(k < w && a[i][k]){
                    a[i][k] = false;
                    k++;
                }
                k = j - 1;
                while(k >= 0 && a[i][k]){
                    a[i][k] = false;
                    k--;
                }
                ok = true;
                break;
            }
        }
        if(ok){
            break;
        }
    }

    if(not ok){
        cout << "NO" << endl;
        return 0;
    }

    rep(i, h){
        rep(j, w){
            if(a[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}
