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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> len(n);
    int x = 1;
    rep(i, n){
        len[i] = x++;

        if(a[i] > a[i+1]){
            x = 1;
        }
    }

    set<int> s;
    rep(i, k){
        s.insert(a[i]);
    }

    int ans = 1;
    if(len[k-1] >= k){
        ans--;
    }

    for(int i = k; i < n; i++){
        bool ok = false;
        if(a[i-k] > *s.begin()){
            ok = true;
        }
        s.erase(a[i-k]);

        auto it = s.end();
        it--;
        if(a[i] < *it){
            ok = true;
        }
        s.insert(a[i]);

        if(ok && len[i] < k){
            ans++;
        }
    }

    int eq = 0;
    rep(i, n){
        if(len[i] >= k){
            eq++;
        }
    }

    if(eq > 0){
        ans++;
    }
    cout << ans << endl;

    return 0;
}
