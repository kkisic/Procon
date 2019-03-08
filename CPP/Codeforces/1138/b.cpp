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
    string c, a;
    cin >> c >> a;

    auto x = initVec3<int>(2, 2, 0);
    rep(i, n){
        rep(j, 2){
            rep(k, 2){
                if(c[i] - '0' == j && a[i] - '0' == k){
                    x[j][k].push_back(i + 1);
                }
            }
        }
    }

    if(SZ(x[0][1]) > n / 2 || SZ(x[1][0]) > n / 2){
        cout << -1 << endl;
        return 0;
    }
    if(SZ(x[0][0]) % 2 == 1 && SZ(x[1][1]) % 2 == 1 && SZ(x[0][0]) + SZ(x[1][1]) == n){
        cout << -1 << endl;
        return 0;
    }

    for(int k = 0; k <= n / 2; k++){
        if(SZ(x[1][1]) + SZ(x[1][0]) < k){
            continue;
        }
        for(int i = 0; i <= k; i++){
            if(SZ(x[1][1]) < i || SZ(x[1][1]) - i > k){
                continue;
            }
            if(SZ(x[1][0]) < k - i){
                continue;
            }
            if(SZ(x[0][1]) < k - SZ(x[1][1]) + i){
                continue;
            }
            int ex0 = SZ(x[0][1]) - k + SZ(x[1][1]) - i;
            int ex1 = SZ(x[1][0]) - k + i;
            if(ex0 > n / 2 - k || ex1 > n / 2 - k){
                continue;
            }

            rep(j, i){
                cout << x[1][1][j] << " ";
            }
            rep(j, k - i){
                cout << x[1][0][j] << " ";
            }
            rep(j, ex0){
                cout << x[0][1][j] << " ";
            }
            rep(j, n / 2 - k - ex0){
                cout << x[0][0][j] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
