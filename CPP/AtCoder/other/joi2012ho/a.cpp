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

    vector<int> c(26);
    c['O'-'A'] = 1;
    c['I'-'A'] = 2;

    string s;
    cin >> s;

    vector<pair<int, int>> v;
    rep(i, SZ(s)){
        if(v.empty() || v.back().first != c[s[i]-'A']){
            v.emplace_back(c[s[i]-'A'], 1);
            continue;
        }
        v.back().second++;
    }

    int ans = 0;
    rep(i, SZ(v) - 2){
        if(v[i].first == v[i+1].first - 1 && v[i].first == v[i+2].first - 2
                && v[i].second >= v[i+1].second && v[i+1].second <= v[i+2].second){
            ans = max(ans, v[i+1].second);
        }
    }
    cout << ans << endl;

    return 0;
}
