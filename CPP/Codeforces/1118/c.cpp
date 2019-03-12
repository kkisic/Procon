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
    vector<int> a(n * n);
    rep(i, n * n) cin >> a[i];
    vector<int> b(1001);
    rep(i, n * n){
        b[a[i]]++;
    }
    sort(ALL(a));
    UNIQUE(a);

    auto ans = initVec2<int>(n, n);
    int id = 0;
    rep(i, n / 2){
        rep(j, n / 2){
            while(id <= 1000 && b[id] < 4){
                id++;
            }
            if(id > 1000){
                cout << "NO" << endl;
                return 0;
            }
            ans[i][j] = id;
            b[id] -= 4;
        }
    }

    id = 0;
    if(n % 2){
        rep(i, n / 2){
            while(id <= 1000 && b[id] < 2){
                id++;
            }
            if(id > 1000){
                cout << "NO" << endl;
                return 0;
            }
            ans[n/2][i] = id;
            b[id] -= 2;
        }
        rep(i, n / 2){
            while(id <= 1000 && b[id] < 2){
                id++;
            }
            if(id > 1000){
                cout << "NO" << endl;
                return 0;
            }
            ans[i][n/2] = id;
            b[id] -= 2;
        }
    }

    rep(i, 1000){
        if(b[i] == 1){
            ans[n/2][n/2] = i;
        }
    }

    rep(i, (n + 1) / 2){
        rep(j, (n + 1) / 2){
            ans[n-1-i][j] = ans[i][j];
            ans[i][n-1-j] = ans[i][j];
            ans[n-1-i][n-1-j] = ans[i][j];
        }
    }

    cout << "YES" << endl;
    rep(i, n){
        rep(j, n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
