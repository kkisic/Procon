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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat multi(Mat a, Mat b){
    Mat c(a.size(), Vec(b[0].size()));

    rep(i, (int)a.size()){
        rep(j, (int)b[0].size()){
            rep(k, (int)b.size()){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

Vec multi(Mat a, Vec b){
    Vec c(a.size());

    rep(i, (int)a.size()){
        rep(j, (int)b.size()){
            c[i] += a[i][j] * b[j];
        }
    }
    return c;
}

signed main(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> cmd(n), d(n);
    rep(i, n){
        cin >> cmd[i];
        if(cmd[i] != 3){
            cin >> d[i];
        }
    }

    //vector<int> px(n+1), py(n+1);
    vector<Mat> mat(n+1, Mat(3, Vec(3)));
    mat[n][0][0] = 1;
    mat[n][1][1] = 1;
    mat[n][2][2] = 1;
    for(int i = n-1; i >= 0; i--){
        Mat m(3, Vec(3));

        if(cmd[i] == 1){
            m[0][0] = 1;
            m[1][1] = 1;
            m[2][2] = 1;
            m[0][2] = d[i];
        }
        if(cmd[i] == 2){
            m[0][0] = 1;
            m[1][1] = 1;
            m[2][2] = 1;
            m[1][2] = d[i];
        }
        if(cmd[i] == 3){
            m[0][1] = 1;
            m[1][0] = -1;
            m[2][2] = 1;
        }
        mat[i] = multi(mat[i+1], m);
    }

    Vec v(3);
    v[0] = x;
    v[1] = y;
    v[2] = 1;
    rep(i, n){
        Vec ans = multi(mat[i], v);
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}
