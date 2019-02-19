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

    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    string s;
    cin >> s;

    int h = x2 - x1;
    int v = y2 - y1;

    int u, d, l, r;
    u = d = l = r = 0;
    rep(i, n){
        if(s[i] == 'L'){
            l++;
        }
        if(s[i] == 'R'){
            r++;
        }
        if(s[i] == 'D'){
            d++;
        }
        if(s[i] == 'U'){
            u++;
        }
    }


    if(h == 0 && v == 0){
        cout << 0 << endl;
        return 0;
    }
    if(r - l + u - d + n <= 0){
        cout << -1 << endl;
        return 0;
    }

    int lo = -1;
    int hi = 1e15;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;

        int c = mid / n;
        int x = (r - l) * c;
        int y = (u - d) * c;
        rep(i, mid % n){
            if(s[i] == 'L'){
                x--;
            }
            if(s[i] == 'R'){
                x++;
            }
            if(s[i] == 'D'){
                y--;
            }
            if(s[i] == 'U'){
                y++;
            }
        }

        if(abs(h - x) + abs(v - y) <= mid){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    if(hi != 1e15){
        cout << hi << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
