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

    int a, b, c;
    cin >> a >> b >> c;
    int m = a + b + c;
    vector<int> ans(m + 1, 2);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> ir;
    rep(i, n){
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        if(w == 0){
            ir.emplace_back(x, y, z);
            continue;
        }
        ans[x] = ans[y] = ans[z] = 1;
    }

    rep(i, SZ(ir)){
        int x, y, z;
        tie(x, y, z) = ir[i];

        if(ans[x] == 1 && ans[y] == 1){
            ans[z] = 0;
        }
        if(ans[y] == 1 && ans[z] == 1){
            ans[x] = 0;
        }
        if(ans[z] == 1 && ans[x] == 1){
            ans[y] = 0;
        }
    }

    rep(i, m){
        cout << ans[i+1] << endl;
    }

    return 0;
}
