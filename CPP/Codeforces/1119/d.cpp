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
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];

    sort(ALL(s));
    UNIQUE(s);
    int nn = SZ(s);

    map<int, int> diff;
    rep(i, nn - 1){
        diff[s[i+1]-s[i]]++;
    }

    vector<int> d(SZ(diff) + 1), unzip(SZ(diff) + 1);
    int i = 1;
    for(auto it = diff.begin(); it != diff.end(); it++){
        unzip[i] = it->first;
        d[i] = it->second;
        i++;
    }

    vector<int> sum(SZ(diff) + 1);
    vector<int> f(SZ(diff) + 1);
    rep(i, SZ(sum) - 1){
        sum[i+1] = sum[i] + (unzip[i+1] - unzip[i]) * (nn - f[i]);
        f[i+1] += f[i] + d[i+1];
    }

    int q;
    cin >> q;
    while(q > 0){
        int l, r;
        cin >> l >> r;
        r -= l;
        r++;

        int lo = 0;
        int hi = SZ(unzip);
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(unzip[mid] < r){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        int ans = sum[lo];
        int len = r - unzip[lo];
        ans += (nn - f[lo]) * len;
        cout << ans << " ";
        q--;
    }
    cout << endl;

    return 0;
}
