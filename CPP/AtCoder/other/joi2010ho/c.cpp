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

    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    priority_queue<P> pq;
    vector<bool> used(n);
    rep(i, n){
        int ok = true;
        if(i - 1 >= 0 && a[i] <= a[i-1]){
            ok = false;
        }
        if(i + 1 < n && a[i] <= a[i+1]){
            ok = false;
        }
        if(ok){
            pq.emplace(a[i], i);
            used[i] = true;
        }
    }

    int now = 0;
    vector<int> ans(n);
    while(not pq.empty()){
        int h = pq.top().first;
        int id = pq.top().second;
        pq.pop();

        now = ans[id] = l - h;
        a[id] = 0;

        if(id - 1 >= 0){
            bool ok = true;
            if(id - 2 >= 0 && a[id-1] <= a[id-2]){
                ok = false;
            }
            if(ok && a[id-1] != 0 && not used[id-1]){
                pq.emplace(a[id-1] - now, id - 1);
                used[id-1] = true;
            }
        }
        if(id + 1 < n){
            bool ok = true;
            if(id + 2 < n && a[id+1] <= a[id+2]){
                ok = false;
            }
            if(ok && a[id+1] != 0 && not used[id+1]){
                pq.emplace(a[id+1] - now, id + 1);
                used[id+1] = true;
            }
        }
    }

    int maxi = 0;
    rep(i, n){
        maxi = max(maxi, ans[i]);
    }
    cout << maxi << endl;

    return 0;
}
