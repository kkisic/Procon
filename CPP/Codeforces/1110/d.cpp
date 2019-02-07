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

const int INF = 1e9;
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

    int n, m;
    cin >> n >> m;
    map<int, int> a;
    rep(i, n){
        int x;
        cin >> x;
        a[x]++;
    }

    auto dp = initVec3<int>(m + 1, 5, 3, -INF);
    dp[0][0][0] = 0;
    rep(i, m){
        rep(j, 5){
            rep(k, 3){
                if(dp[i][j][k] == -INF){
                    continue;
                }
                int able = min(j, k);
                able = min(able, a[i+1]);
                for(int l = 0; l <= able; l++){
                    int x = (a[i+1] - l) / 3;
                    int y = (a[i+1] - l) % 3;
                    int w = min(j - l, 2);
                    dp[i+1][y][w] = max(dp[i+1][y][w], dp[i][j][k] + l + x);

                    if(x > 0){
                        int z = min(y + 3, 4);
                        dp[i+1][z][w] = max(dp[i+1][z][w], dp[i][j][k] + l + x - 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(i, 5){
        rep(j, 3){
            ans = max(ans, dp[m][i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}
