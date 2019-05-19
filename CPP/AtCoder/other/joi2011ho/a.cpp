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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

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

int J[1001][1001];
int O[1001][1001];
int cj[1001][1001];
int co[1001][1001];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    rep(i, m){
        char s[1001];
        scanf("%s", s);
        rep(j, n){
            if(s[j] == 'J'){
                J[i][j] = 1;
            }else{
                J[i][j] = 0;
            }
            if(s[j] == 'O'){
                O[i][j] = 1;
            }else{
                O[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cj[i][j] += J[i-1][j-1] + cj[i-1][j] + cj[i][j-1] - cj[i-1][j-1];
            co[i][j] += O[i-1][j-1] + co[i-1][j] + co[i][j-1] - co[i-1][j-1];
        }
    }

    rep(i, k){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a--;
        b--;
        int jj = cj[c][d] - cj[c][b] - cj[a][d] + cj[a][b];
        int oo = co[c][d] - co[c][b] - co[a][d] + co[a][b];
        cout << jj << " " << oo << " " << (c - a) * (d - b) - (jj + oo) << endl;
    }

    return 0;
}
