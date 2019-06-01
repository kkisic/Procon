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
    vector<int> p(n);
    vector<int> pos(n + 1);
    rep(i, n){
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<P> ans;
    for(int i = 1; i <= n; i++){
        if(pos[i] == i - 1){
            continue;
        }

        int src = pos[i] + 1;
        int dst = i;
        if(src > dst){
            swap(src, dst);
        }
        if(abs(src - dst) >= n / 2){
            ans.emplace_back(src, dst);
        }else{
            if(src <= n / 2 && dst <= n / 2){
                ans.emplace_back(src, n);
                ans.emplace_back(dst, n);
                ans.emplace_back(src, n);
            }else if(src > n / 2 && src > n / 2){
                ans.emplace_back(src, 1);
                ans.emplace_back(dst, 1);
                ans.emplace_back(src, 1);
            }else{
                ans.emplace_back(1, dst);
                ans.emplace_back(1, n);
                ans.emplace_back(src, n);
                ans.emplace_back(1, n);
                ans.emplace_back(1, dst);
            }
        }
        swap(pos[p[src-1]], pos[p[dst-1]]);
        swap(p[src-1], p[dst-1]);
    }

    cout << SZ(ans) << endl;
    rep(i, SZ(ans)){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
