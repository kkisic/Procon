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

int n, k, a, b;
vector<int> pos, sum;
map<int, int> m;

//[l, r)
int solve(int l, int r, int p){
    if(p == 0){
        if(m[l] > 0){
            return b * m[l];
        }
        return a;
    }
    int lo, hi;
    lo = 0;
    hi = SZ(pos);
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(pos[mid] < l){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    int s = lo;

    lo = 0;
    hi = SZ(pos);
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(pos[mid] < r){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    int t = lo;

    int cnt = sum[t] - sum[s];
    if(cnt == 0){
        return a;
    }
    int ans = solve(l, l + (r - l) / 2, p - 1);
    ans += solve(l + (r - l) / 2, r, p - 1);
    return min(ans, cnt * b * (r - l));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> a >> b;

    vector<int> x(k);
    m = map<int, int>();
    rep(i, k){
        cin >> x[i];
        m[x[i]]++;
    }

    pos = vector<int>();
    sum = vector<int>();
    pos.push_back(0);
    sum.push_back(0);
    for(P p : m){
        pos.push_back(p.first);
        sum.push_back(p.second + sum.back());
    }
    pos.push_back(1LL << 31);
    sum.push_back(sum.back());

    cout << solve(1, (1LL << n) + 1, n) << endl;

    return 0;
}
