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

pair<map<int, int>, vector<int>> compress(const vector<int>& a){
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<int, int> zip;
    rep(i, (int)b.size()){
        zip[b[i]] = i;
    }
    return {zip, b};
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    n++;
    a.push_back(0);

    auto pp = compress(a);
    map<int, int> zip = pp.first;
    vector<int> unzip = pp.second;

    vector<int> cnt(101010), edge(101010);
    rep(i, n - 1){
        edge[min(zip[a[i]], zip[a[i+1]])]++;
    }
    rep(i, n){
        cnt[zip[a[i]]]++;
    }

    int sum = 0;
    int e = 0;
    int ans = 0;
    for(int i = 100000; i >= 1; i--){
        sum += cnt[i];
        e += edge[i];
        ans = max(ans, sum - e);
    }
    cout << ans << endl;

    return 0;
}
