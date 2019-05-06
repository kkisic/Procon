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

typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat multi(Mat a, Mat b){
    Mat c(a.size(), Vec(b[0].size()));

    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b[0].size(); j++){
            for(int k = 0; k < (int)b.size(); k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}

Vec multi(Mat a, Vec b){
    Vec c(a.size());

    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b.size(); j++){
            c[i] = (c[i] + a[i][j] * b[j] % MOD) % MOD;
        }
    }
    return c;
}

Mat powMat(Mat a, int n){
    Mat b(a.size(), Vec(a[0].size()));
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)a[0].size(); j++){
            if(i == j){
                b[i][j] = 1;
            }
        }
    }

    while(n != 0){
        if(n % 2 == 1){
            b = multi(b, a);
        }

        n /= 2;
        a = multi(a, a);
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n *= 3;

    Mat m(8, Vec(8));
    m[0][6] = 1;
    m[0][7] = 1;
    m[1][5] = 1;
    m[1][7] = 1;
    m[2][1] = 1;
    m[3][0] = 1;
    m[4][0] = 1;
    m[4][1] = 1;
    m[5][3] = 1;
    m[5][4] = 1;
    m[6][2] = 1;
    m[6][4] = 1;
    m[7][2] = 1;
    m[7][3] = 1;

    Vec v(8);
    v[0] = v[1] = 1;

    Vec va = multi(powMat(m, n - 1), v);
    int ans = 0;
    rep(i, 8){
        ans += va[i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
