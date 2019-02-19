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

//Mat[0] : 第0行ベクトル
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

    int n, m;
    cin >> n >> m;
    if(n < m){
        cout << 1 << endl;
        return 0;
    }

    Mat mat(m, Vec(m));
    mat[0][0] = 1;
    mat[0][m-1] = 1;
    rep(i, m - 1){
        mat[i+1][i] = 1;
    }

    Vec v(m, 1);
    int r = n - m + 1;
    Vec u = multi(powMat(mat, r), v);
    cout << u[0] << endl;

    return 0;
}
