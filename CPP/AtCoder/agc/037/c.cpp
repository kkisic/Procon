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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    priority_queue<P> pq;
    rep(i, n){
        pq.emplace(b[i], i);
    }

    int ans = 0;
    while(not pq.empty()){
        int x = pq.top().first;
        int id = pq.top().second;
        pq.pop();

        if(x <= a[id]){
            continue;
        }

        int sum = b[(id+n-1)%n] + b[(id+1)%n];
        int cnt = (x - a[id]) / sum;
        ans += cnt;
        b[id] -= sum * cnt;

        if(b[id] > a[id] && x != b[id]){
            pq.emplace(b[id], id);
        }
    }

    rep(i, n){
        if(a[i] != b[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
