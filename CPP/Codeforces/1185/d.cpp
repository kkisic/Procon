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
    vector<P> b(n);
    rep(i, n){
        int x;
        cin >> x;
        b[i] = {x, i + 1};
    }

    sort(ALL(b));
    vector<int> d;
    rep(i, n - 1){
        d.push_back(b[i+1].first - b[i].first);
    }

    bool ok = true;
    for(int i = 1; i < SZ(d); i++){
        if(d[1] != d[i]){
            ok = false;
        }
    }
    if(ok){
        cout << b[0].second << endl;
        return 0;
    }
    ok = true;
    for(int i = 0; i < SZ(d) - 1; i++){
        if(d[0] != d[i]){
            ok = false;
        }
    }
    if(ok){
        cout << b.back().second << endl;
        return 0;
    }

    int maxi = 0;
    rep(i, SZ(d)){
        maxi = max(maxi, d[i]);
    }
    ok = true;
    int ans = -1;
    rep(i, SZ(d)){
        if(d[i] == maxi){
            continue;
        }
        if(i < SZ(d) - 1){
            if(d[i] + d[i+1] != maxi){
                ok = false;
            }else{
                if(ans == -1){
                    ans = b[i+1].second;
                    i++;
                }else{
                    ok = false;
                }
            }
        }else{
            ok = false;
        }
    }

    if(not ok){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}
