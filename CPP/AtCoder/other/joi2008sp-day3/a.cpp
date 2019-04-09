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

    int n, a, b;
    cin >> n >> a >> b;

    map<P, int> m;
    rep(i, n){
        int p, q, r, s;
        cin >> p >> q >> r >> s;

        for(int j = p; j <= r; j++){
            for(int k = q; k <= s; k++){
                m[make_pair(j, k)]++;
            }
        }
    }

    int maxi = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        maxi = max(maxi, it->second);
    }
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == maxi){
            ans++;
        }
    }
    cout << maxi << endl;
    cout << ans << endl;

    return 0;
}
