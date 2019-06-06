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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto dp = initVec2<int>(n + 1, k + 1);
    for(int j = 0; j < k; j++){
        deque<int> deq;
        int l = 0;
        for(int i = 0; i < n; i++){
            while(not deq.empty() && dp[deq.back()][j] <= dp[i][j]){
                deq.pop_back();
            }

            deq.push_back(i);

            if(i - l >= m){
                if(deq.front() == l){
                    deq.pop_front();
                }
                l++;
            }
            if(i >= j){
                dp[i+1][j+1] = dp[deq.front()][j] + a[i] * (j + 1);
            }
        }
    }

    int ans = 0;
    rep(i, n + 1){
        ans = max(ans, dp[i][k]);
    }
    cout << ans << endl;

    return 0;
}
