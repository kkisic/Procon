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

    int k, n, m;
    cin >> k >> n >> m;
    vector<int> p(k);
    rep(i, k) cin >> p[i];

    if(k == 1){
        cout << 1 << endl;
        cout << "--------" << endl;
        cout << 1 << endl;
        return 0;
    }

    vector<int> q = p;
    sort(ALL(q), greater<int>());
    int g = (k + 11) / 12;

    int x = (n - m) * 100;

    rep(i, k){
        if(p[i] >= q[g-1] && p[i] >= q[g] + x){
            cout << i + 1 << endl;
        }else if(p[i] <= q[g] && p[i] >= q[g-1] + x){
            cout << i + 1 << endl;
        }
    }

    cout << "--------" << endl;

    rep(i, k){
        if(p[i] + x >= q[g-1]){
            cout << i + 1 << endl;
        }
    }

    return 0;
}
