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
    string s;
    cin >> n >> s;

    vector<P> range;
    int head = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(head == -1){
                head = i;
            }
            continue;
        }
        if(head != -1 && i - head >= 1){
            range.emplace_back(head, i - 1);
        }
        head = -1;
    }
    if(head != -1 && n - head >= 1){
        range.emplace_back(head, n - 1);
    }

    auto c = initVec2<P>(n, 0);
    for(P p : range){
        if(p.first - 2 >= 0 && s.substr(p.first-2, 3) == "101"){
            c[p.first-2].emplace_back(p.second + 1, p.second - p.first + 1);
            if(p.second - p.first + 1 >= 2){
                c[p.first-2].emplace_back(p.second, p.second - p.first);
            }
        }
        if(p.second + 2 < n && s.substr(p.second, 3) == "101"){
            c[p.first].emplace_back(p.second + 3, p.second - p.first + 1);
            if(p.second - p.first + 1 >= 2){
                c[p.first+1].emplace_back(p.second + 3, p.second - p.first);
            }
        }
    }

    vector<int> dp(n + 1);
    rep(i, n){
        for(P p : c[i]){
            dp[p.first] = max(dp[p.first], dp[i] + p.second);
        }
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    cout << dp[n] << endl;

    return 0;
}
