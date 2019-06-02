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

    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    if(n <= k){
        cout << -1 << endl;
        return 0;
    }

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] += ta;
    }
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    b.push_back(INF);
    m = SZ(b);

    int ans = -1;
    int j = 0;
    rep(i, n){
        int r = k - i;
        if(r < 0){
            continue;
        }

        while(j < m - 1 && a[i] > b[j]){
            j++;
        }
        ans = max(ans, b[min(j+r, m-1)]);
    }

    if(ans >= INF){
        cout << -1 << endl;
    }else{
        cout << ans + tb << endl;
    }

    return 0;
}
