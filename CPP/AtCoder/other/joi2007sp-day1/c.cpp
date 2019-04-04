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

//a[s][t] = 0 <= i < s, 0 <= j < t
template <typename T>
class Cumulative{
    public:
        int h, w;
        vector<vector<T>> c, a;

        Cumulative(const vector<vector<T>>& c, int h, int w)
            : h(h), w(w), c(c), a(h+1, vector<T>(w+1)) {
                for(int i = 1; i <= h; i++){
                    for(int j = 1; j <= w; j++){
                        a[i][j] += c[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                    }
                }
            }

        T query(int i, int j, int k, int l){
            return a[k][l] - a[k][j] - a[i][l] + a[i][j];
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    int a, b;
    cin >> a >> b;

    auto c = initVec2<int>(n, m);
    rep(i, n) rep(j, m){
        cin >> c[i][j];
        if(c[i][j] == -1){
            c[i][j] = 1e9;
        }
    }

    Cumulative<int> cum(c, n, m);
    int ans = INF;
    rep(i, n - b){
        rep(j, m - a){
            ans = min(ans, cum.query(i, j, i + b, j + a));
        }
    }
    cout << ans << endl;

    return 0;
}
