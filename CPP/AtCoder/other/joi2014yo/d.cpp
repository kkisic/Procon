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
const int MOD = 10007;

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
    vector<int> s(n);
    rep(i, n){
        char c;
        cin >> c;
        if(c == 'J'){
            s[i] = 0;
        }
        if(c == 'O'){
            s[i] = 1;
        }
        if(c == 'I'){
            s[i] = 2;
        }
    }

    auto dp = initVec2<int>(n, 8);
    rep(i, 8){
        if((i >> s[0]) % 2 && i % 2){
            dp[0][i] = 1;
        }
    }
    rep(i, n - 1){
        rep(j, 8){
            rep(k, 8){
                if((k >> s[i+1]) % 2 == 0){
                    continue;
                }
                if((j & k) != 0){
                    dp[i+1][k] += dp[i][j];
                    dp[i+1][k] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    rep(i, 8){
        if((i >> s.back()) % 2 == 0){
            continue;
        }
        ans += dp[n-1][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
