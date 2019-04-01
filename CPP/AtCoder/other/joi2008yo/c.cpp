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
    vector<bool> used(2 * n + 1, false);
    vector<int> t(n), h;
    rep(i, n){
        cin >> t[i];
        used[t[i]] = true;
    }
    for(int i = 1; i <= 2 * n; i++){
        if(used[i]){
            continue;
        }
        h.push_back(i);
    }
    sort(ALL(t));

    int now = 0;
    while(not t.empty() && not h.empty()){
        int pre = now;
        for(auto it = t.begin(); it != t.end();){
            if(now > *it){
                it++;
            }else{
                now = *it;
                it = t.erase(it);
                break;
            }
        }
        if(now == pre){
            now = 0;
        }

        if(t.empty() || h.empty()){
            break;
        }

        pre = now;
        for(auto it = h.begin(); it != h.end();){
            if(now > *it){
                it++;
            }else{
                now = *it;
                it = h.erase(it);
                break;
            }
        }
        if(now == pre){
            now = 0;
        }
    }

    if(t.empty()){
        cout << SZ(h) << endl;
        cout << 0 << endl;
    }else{
        cout << 0 << endl;
        cout << SZ(t) << endl;
    }

    return 0;
}
