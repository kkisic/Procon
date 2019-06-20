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

#define int long long
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto O = initVec2<int>(h, w);
    auto I = initVec2<int>(h, w);
    rep(i, h){
        rep(j, w){
            if(s[i][j] == 'O'){
                O[i][j] = 1;
            }
            if(s[i][j] == 'I'){
                I[i][j] = 1;
            }
        }
    }

    rep(i, h){
        for(int j = w - 1; j > 0; j--){
            O[i][j-1] += O[i][j];
        }
    }
    rep(j, w){
        for(int i = h - 1; i > 0; i--){
            I[i-1][j] += I[i][j];
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w){
        if(s[i][j] != 'J'){
            continue;
        }
        ans += O[i][j] * I[i][j];
    }
    cout << ans << endl;

    return 0;
}
