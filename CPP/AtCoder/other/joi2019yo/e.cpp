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

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i+1];
    vector<P> range(m);
    rep(i, m){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    //dp1[i] : i以下でiと同一区間にならない木の番号の最大
    vector<int> dp1(n + 1, INF);
    dp1[n] = n - 1;
    rep(i, m){
        dp1[range[i].second] = min(dp1[range[i].second], range[i].first - 1);
    }
    for(int i = n - 1; i >= 0; i--){
        dp1[i] = min(dp1[i], min(dp1[i+1], i - 1));
    }

    //dp2[i] : i番目を選択するときの最大値(iと区間が被らない最大値(maxi[dp1[i]]) + a[i])
    //maxi[i] : i番目まで見たときの最大値
    vector<int> dp2(n + 1), maxi(n + 1);
    for(int i = 1; i <= n; i++){
        dp2[i] = max(dp2[i], maxi[dp1[i]] + a[i]);
        maxi[i] = max(maxi[i-1], dp2[i]);
    }
    cout << maxi[n] << endl;

    return 0;
}
