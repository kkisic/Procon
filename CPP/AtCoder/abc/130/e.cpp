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

int solve(vector<int>& s, vector<int>& t){
    vector<vector<int>> dp((int)s.size() + 1, vector<int>((int)t.size() + 1));
    vector<vector<int>> sum((int)s.size() + 1, vector<int>((int)t.size() + 1));
    for(int i = 0; i <= (int)s.size(); i++){
        for(int j = 0; j <= (int)t.size(); j++){
            if(i + 1 <= (int)s.size() && j + 1 <= (int)t.size()){
                if(s[i] == t[j]){
                    dp[i+1][j+1] = sum[i][j] + 1;
                }
                sum[i+1][j+1] = (MOD + sum[i+1][j] + sum[i][j+1] - sum[i][j] + dp[i+1][j+1]) % MOD;
            }
        }
    }

    return (sum[SZ(s)][SZ(t)] + 1) % MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    cout << solve(s, t) << endl;

    return 0;
}
