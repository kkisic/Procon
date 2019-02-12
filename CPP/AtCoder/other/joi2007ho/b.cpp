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
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    sort(ALL(a));

    bool isBlank = false;
    int i = 0;
    if(a[i] == 0){
        isBlank = true;
        i++;
    }

    vector<P> r;
    r.emplace_back(a[i], a[i]);
    i++;
    while(i < k){
        if(a[i] == a[i-1] + 1){
            r.back().second++;
            i++;
            continue;
        }
        r.emplace_back(a[i], a[i]);
        i++;
    }

    int single = 0;
    rep(i, SZ(r)){
        single = max(single, r[i].second - r[i].first + 1);
    }
    if(not isBlank){
        cout << single << endl;
        return 0;
    }

    int w = 0;
    rep(i, SZ(r) - 1){
        if(r[i].second + 2 == r[i+1].first){
            w = max(w, r[i+1].second - r[i].first + 1);
        }
    }
    cout << max(single + 1, w) << endl;

    return 0;
}
