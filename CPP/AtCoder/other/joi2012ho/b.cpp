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

//Longest Common Subsequence
int lcs(vector<int>& s, vector<int>& t){
    int n = (int)s.size();
    int m = (int)t.size();

    vector<vector<int>> dp((int)s.size() + 1, vector<int>((int)t.size() + 1));
    for(int i = 0; i <= (int)s.size(); i++){
        for(int j = 0; j <= (int)t.size(); j++){
            if(i + 1 <= (int)s.size()){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
            if(i + 1 <= (int)s.size() && j + 1 <= (int)t.size() && s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            }
        }
    }

    int ans = 0;
    rep(i, n + 1){
        rep(j, m + 1){
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(m);
    rep(i, m) cin >> b[i];

    cout << lcs(a, b) << endl;

    return 0;
}
