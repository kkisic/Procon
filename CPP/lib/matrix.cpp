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
const int MOD = 1e9+7;

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

//int型で2値ベクトルを表現してる場合の掃き出し法
//a: 行列, k: 次元数
vector<int> gaussian_bit(vector<int> a, int k){
    int n = a.size();
    set<int> as;

    rep(i, k){
        int axis = -1;
        rep(j, n){
            if((a[j] >> i) % 2 == 1 && as.find(j) == as.end()){
                axis = j;
                as.insert(j);
                break;
            }
        }

        if(axis == -1){
            continue;
        }

        rep(j, n){
            if(j == axis){
                continue;
            }
            if((a[j] >> i) % 2 == 1){
                a[j] ^= a[axis];
            }
        }
    }
    sort(a.begin(), a.end());

    return a;
}