#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 17;

typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat multi(Mat a, Mat b){
    Mat c(a.size(), Vec(b[0].size()));

    rep(i, (int)a.size()){
        rep(j, (int)b[0].size()){
            rep(k, (int)b.size()){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}

Vec multi(Mat a, Vec b){
    Vec c(a.size());

    rep(i, (int)a.size()){
        rep(j, (int)b.size()){
            c[i] = (c[i] + a[i][j] * b[j] % MOD) % MOD;
        }
    }
    return c;
}

Mat powMat(Mat a, int n){
    Mat b(a.size(), Vec(a[0].size()));;
    rep(i, (int)a.size()){
        rep(j, (int)a[0].size()){
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
    Mat x(4, Vec(4));
    x[0][0] = x[0][1] = x[0][2] = x[0][3] = x[1][0] = x[2][1] = x[3][2] = 1;
    Vec v = {1, 0, 0, 0};
    int q;
    cin >> q;
    rep(i, q){
        int n;
        cin >> n;

        if(n <= 4){
            cout << v[4-n] << endl;
            continue;
        }

        Vec ans = multi(powMat(x, n-4), v);
        cout << ans[0] << endl;
    }

    return 0;
}
