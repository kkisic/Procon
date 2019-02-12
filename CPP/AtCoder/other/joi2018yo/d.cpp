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

    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    vector<int> sum(n + 1);
    rep(i, n) sum[i+1] = sum[i] + l[i];

    //部分長として有り得るもの(一度も切ってない物を除く)
    vector<int> sub;
    rep(i, n){
        for(int j = i + 1; j <= n; j++){
            sub.push_back(sum[j] - sum[i]);
        }
    }
    sort(ALL(sub));
    UNIQUE(sub);
    sub.pop_back();

    int ans = INF;
    rep(i, SZ(sub)){
        //dp[j] : [0, j)をsub[i]以上の長さで切り分けた時の最大長
        //dp[j] = -INFの時は切り分け不可
        vector<int> dp(n + 1, -INF);
        dp[0] = 0;
        for(int j = 1; j <= n; j++){
            int tmp = INF;
            for(int k = 0; k < j; k++){
                if(j == n && k == 0){
                    continue;
                }
                if(sum[j] - sum[k] < sub[i]){
                    continue;
                }
                if(dp[k] == -INF){
                    continue;
                }
                tmp = min(tmp, max(dp[k], sum[j] - sum[k]));
            }
            if(tmp != INF){
                dp[j] = tmp;
            }
        }
        if(dp[n] != -INF){
            ans = min(ans, dp[n] - sub[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
