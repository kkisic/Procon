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

    vector<int> p(50);
    p[0] = 1;
    for(int i = 1; i < 50; i++){
        p[i] = p[i-1] * 2;
    }

    int q;
    cin >> q;
    while(q--){
        int a, b, m;
        cin >> a >> b >> m;

        if(a == b){
            cout << 1 << " " << a << endl;
            continue;
        }

        int lo = a + 1;
        int hi = a + m;
        int len = 1;
        for(; len <= 49; len++){
            if(lo <= b && b <= hi){
                break;
            }
            lo *= 2;
            hi *= 2;
            if(lo > INF){
                break;
            }
        }

        if(lo > INF){
            cout << -1 << endl;
            continue;
        }

        if(len > 49){
            cout << -1 << endl;
            continue;
        }

        vector<int> ans(len + 1);
        ans[0] = a;
        ans[1] = a + 1;
        for(int i = 1; i < len; i++){
            ans[i+1] = ans[i] * 2;
        }

        int d = b - lo;
        for(int i = 1; i <= len; i++){
            int x = max(len - (i + 1), 0LL);
            int y = min(d / p[x], m - 1);
            d -= p[x] * y;
            ans[i] += y;
            for(int j = i + 1; j <= len; j++){
                ans[j] += y;
                y *= 2;
            }
        }

        cout << len + 1;
        rep(i, len + 1){
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}
