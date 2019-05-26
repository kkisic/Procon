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

    int n, k;
    cin >> n >> k;
    deque<int> v(n);
    rep(i, n) cin >> v[i];

    auto l = initVec2<int>(n + 1, n + 1);
    auto r = initVec2<int>(n + 1, n + 1);
    vector<int> p, m;
    int sp, sm;
    sp = sm = 0;
    rep(i, n){
        if(v[i] >= 0){
            p.push_back(v[i]);
            sp += v[i];
        }else{
            m.push_back(v[i]);
            sm += v[i];
            sort(ALL(m));
        }
        l[i+1][0] = sp + sm;
        int sum = sm;
        int c = 0;
        for(int t = 0; t < SZ(m); t++){
            sum -= m[t];
            c++;
            l[i+1][t+1] = sp + sum;
        }
    }
    p = vector<int>();
    m = vector<int>();
    sp = sm = 0;
    for(int i = n - 1; i >= 0; i--){
        if(v[i] >= 0){
            p.push_back(v[i]);
            sp += v[i];
        }else{
            m.push_back(v[i]);
            sm += v[i];
            sort(ALL(m));
        }
        int j = n - 1 - i;
        r[j+1][0] = sp + sm;
        int sum = sm;
        int c = 0;
        for(int t = 0; t < SZ(m); t++){
            sum -= m[t];
            c++;
            r[j+1][t+1] = sp + sum;
        }
    }

    int ans = 0;
    rep(i, k + 1){
        for(int j = 0; j <= n; j++){
            for(int a = 0; a <= n; a++){
                if(j + a > k || j + a > n){
                    continue;
                }
                for(int b = 0; b <= n; b++){
                    if(j + a + b > k){
                        continue;
                    }
                    for(int c = 0; c <= n; c++){
                        if(j + a + b + c > k){
                            continue;
                        }
                        ans = max(ans, l[j][b] + r[a][c]);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
