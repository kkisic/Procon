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

    int h, w, n;
    cin >> h >> w >> n;
    int x, y;
    cin >> x >> y;
    string s, t;
    cin >> s >> t;

    vector<int> a(4), b(4);
    string d = "LURD";
    rep(i, n){
        rep(k, 4){
            if(d[k] == s[i]){
                a[k]++;
            }
        }

        if(y - max(a[0] - b[2], 0LL) <= 0){
            cout << "NO" << endl;
            return 0;
        }
        if(y + max(a[2] - b[0], 0LL) > w){
            cout << "NO" << endl;
            return 0;
        }
        if(x - max(a[1] - b[3], 0LL) <= 0){
            cout << "NO" << endl;
            return 0;
        }
        if(x + max(a[3] - b[1], 0LL) > h){
            cout << "NO" << endl;
            return 0;
        }

        rep(k, 4){
            if(d[k] == t[i]){
                b[k]++;
            }
        }
        if(y - (b[0] - a[2]) <= 0){
            b[0]--;
        }
        if(y + (b[2] - a[0]) > w){
            b[2]--;
        }
        if(x - (b[1] - a[3]) <= 0){
            b[1]--;
        }
        if(x + (b[3] - a[1]) > h){
            b[3]--;
        }
    }

    cout << "YES" << endl;

    return 0;
}
