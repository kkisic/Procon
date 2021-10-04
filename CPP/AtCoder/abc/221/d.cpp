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
    vector<int> a(n), b(n), all;
    rep(i, n){
        cin >> a[i] >> b[i];
        b[i] += a[i];
        all.push_back(a[i]);
        all.push_back(b[i]);
    }

    auto cmp = compress(all);
    auto encode = cmp.first;
    auto decode = cmp.second;
    int len = encode.size();
    vector<int> sum(len);
    rep(i, n){
        sum[encode[a[i]]] += 1;
        sum[encode[b[i]]] -= 1;
    }
    rep(i, len - 1){
        sum[i+1] += sum[i];
    }
    vector<int> ans(n + 1);
    rep(i, len - 1){
        ans[sum[i]] += decode[i+1] - decode[i];
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
