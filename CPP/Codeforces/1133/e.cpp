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
    rep(i, n) cin >> a[i];
    sort(ALL(a));

    vector<int> len(n);
    int l;
    int r = 0;
    for(l = 0; l < n; l++){
        while(r < n && a[r] - a[l] <= 5){
            r++;
        }
        len[l] = r - l;
    }

    auto dp = initVec2<int>(n + 1, k + 1);
    rep(i, n){
        rep(j, k + 1){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j < k){
                dp[i+len[i]][j+1] = max(dp[i+len[i]][j+1], dp[i][j] + len[i]);
            }
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}
