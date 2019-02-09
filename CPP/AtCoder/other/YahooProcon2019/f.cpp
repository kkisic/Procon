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
const int MOD = 998244353;

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

    string s;
    cin >> s;
    vector<int> r, b;
    rep(i, SZ(s)){
        if(s[i] == '0'){
            r.push_back(i);
            r.push_back(i);
        }
        if(s[i] == '1'){
            r.push_back(i);
            b.push_back(i);
        }
        if(s[i] == '2'){
            b.push_back(i);
            b.push_back(i);
        }
    }

    auto dp = initVec2<int>(SZ(r) + 1, SZ(b) + 1);
    dp[0][0] = 1;
    rep(i, SZ(r) + 1){
        rep(j, SZ(b) + 1){
            if(i < SZ(r) && r[i] <= i + j){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            if(j < SZ(b) && b[j] <= i + j){
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= MOD;
            }
        }
    }
    cout << dp[SZ(r)][SZ(b)] << endl;

    return 0;
}
