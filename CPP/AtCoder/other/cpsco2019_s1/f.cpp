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

int n;
vector<int> t, a, b;

bool check(int x){
    vector<P> r(n);
    rep(i, n){
        if(a[i] - x < 0){
            return false;
        }
        int d = (a[i] - x) / b[i];
        r[i] = {t[i] - d, t[i] + d};
    }
    sort(ALL(r));

    priority_queue<int, vector<int>, greater<int>> pq;
    int pos = 0;
    for(int i = 1; i <= n; i++){
        while(not pq.empty() && pq.top() < i){
            return false;
        }
        while(pos < n && r[pos].first <= i){
            if(r[pos].second >= i){
                pq.push(r[pos].second);
            }
            pos++;
        }

        if(pq.empty()){
            return false;
        }
        pq.pop();
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    t = vector<int>(n);
    a = vector<int>(n);
    b = vector<int>(n);
    rep(i, n) cin >> t[i] >> a[i] >> b[i];

    int lo = -1e10;
    int hi = 1e10;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << lo << endl;

    return 0;
}
