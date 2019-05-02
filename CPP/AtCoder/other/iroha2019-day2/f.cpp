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

double memo[11][11][11][11][11][11];

double dp(int a0, int a1, int b0, int b1, int c0, int c1){
    if(memo[a0][a1][b0][b1][c0][c1] != -INF){
        return memo[a0][a1][b0][b1][c0][c1];
    }
    if(a0 + a1 + b0 + b1 + c0 + c1 == 0){
        return 0;
    }

    if(a0 + a1 > 0){
        double tmp = 0;
        if(a0 > 0){
            tmp += (100 - dp(a0 - 1, a1, b0, b1, c0, c1)) * (double)a0 / (double)(a0 + a1);
        }
        if(a1 > 0){
            tmp += (50 - dp(a0, a1 - 1, b0, b1, c0, c1)) * (double)a1 / (double)(a0 + a1);
        }
        memo[a0][a1][b0][b1][c0][c1] = max(memo[a0][a1][b0][b1][c0][c1], tmp);
    }
    if(b0 + b1 > 0){
        double tmp = 0;
        if(b0 > 0){
            tmp += (100 - dp(a0, a1, b0 - 1, b1, c0, c1)) * (double)b0 / (double)(b0 + b1);
        }
        if(b1 > 0){
            tmp += (50 - dp(a0, a1, b0, b1 - 1, c0, c1)) * (double)b1 / (double)(b0 + b1);
        }
        memo[a0][a1][b0][b1][c0][c1] = max(memo[a0][a1][b0][b1][c0][c1], tmp);
    }
    if(c0 + c1 > 0){
        double tmp = 0;
        if(c0 > 0){
            tmp += (100 - dp(a0, a1, b0, b1, c0 - 1, c1)) * (double)c0 / (double)(c0 + c1);
        }
        if(c1 > 0){
            tmp += (50 - dp(a0, a1, b0, b1, c0, c1 - 1)) * (double)c1 / (double)(c0 + c1);
        }
        memo[a0][a1][b0][b1][c0][c1] = max(memo[a0][a1][b0][b1][c0][c1], tmp);
    }
    return memo[a0][a1][b0][b1][c0][c1];
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> x(6);
    rep(i, 6) cin >> x[i];

    rep(i, 11) rep(j, 11) rep(k, 11) rep(l, 11) rep(m, 11) rep(n, 11){
        memo[i][j][k][l][m][n] = -INF;
    }

    double sum = (x[0] + x[2] + x[4]) * 100.0 + (x[1] + x[3] + x[5]) * 50.0;

    cout << fixed << setprecision(10) << (sum + dp(x[0], x[1], x[2], x[3], x[4], x[5])) / 2.0 << endl;

    return 0;
}
