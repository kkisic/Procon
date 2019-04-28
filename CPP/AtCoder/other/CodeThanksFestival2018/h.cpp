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

int n;
vector<int> a, s;

bool judge(int x){
    auto dp = initVec2<int>(2, n + 1, -INF);
    dp[0][n] = dp[1][n] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j <= n; j++){
            if(s[j] - s[i] >= x){
                dp[0][i] = max(dp[0][i], -dp[1][j] + 1);
                dp[1][i] = max(dp[1][i], -dp[0][j] - 1);
            }else{
                dp[0][i] = max(dp[0][i], -dp[1][j] - 1);
                dp[1][i] = max(dp[1][i], -dp[0][j] + 1);
            }
        }
    }

    return dp[0][0] >= 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];
    s = vector<int>(n + 1);
    rep(i, n) s[i+1] = s[i] + a[i];

    int lo = -1e12;
    int hi = 1e12 + 1;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(judge(mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << lo << endl;

    return 0;
}
