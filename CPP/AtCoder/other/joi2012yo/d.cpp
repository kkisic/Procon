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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, k){
        int x, y;
        cin >> x >> y;
        a[x-1] = y;
    }

    auto dp = initVec3<int>(n + 1, 4, 3);
    dp[0][0][0] = 1;
    rep(i, n){
        for(int j = 0; j <= 3; j++){
            if(a[i] != 0){
                if(a[i] != j){
                    dp[i+1][a[i]][1] += dp[i][j][0];
                    dp[i+1][a[i]][1] %= 10000;
                    dp[i+1][a[i]][1] += dp[i][j][1];
                    dp[i+1][a[i]][1] %= 10000;
                    dp[i+1][a[i]][1] += dp[i][j][2];
                    dp[i+1][a[i]][1] %= 10000;
                }else{
                    dp[i+1][a[i]][2] += dp[i][j][1];
                    dp[i+1][a[i]][2] %= 10000;
                }
                continue;
            }

            for(int k = 1; k <= 3; k++){
                if(j != k){
                    dp[i+1][k][1] += dp[i][j][0];
                    dp[i+1][k][1] %= 10000;
                    dp[i+1][k][1] += dp[i][j][1];
                    dp[i+1][k][1] %= 10000;
                    dp[i+1][k][1] += dp[i][j][2];
                    dp[i+1][k][1] %= 10000;
                }else{
                    dp[i+1][k][2] += dp[i][j][1];
                    dp[i+1][k][1] %= 10000;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 2; j++){
            ans += dp[n][i][j];
            ans %= 10000;
        }
    }
    cout << ans << endl;

    return 0;
}
