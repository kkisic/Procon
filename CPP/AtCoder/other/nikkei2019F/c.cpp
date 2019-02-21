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

    int h, w, k;
    cin >> h >> w >> k;
    vector<int> ch(h + 1, w);
    vector<int> cw(w + 1, h);
    ch[0] = cw[0] = 0;
    rep(i, k){
        int r, c;
        cin >> r >> c;
        ch[r]--;
        cw[c]--;
    }

    for(int i = 1; i < h; i++){
        ch[i+1] += ch[i];
    }
    for(int i = 1; i < w; i++){
        cw[i+1] += cw[i];
    }

    int med = (h * w - k + 1) / 2;
    int mh, mw;
    mh = mw = 0;
    for(int i = 1; i <= h; i++){
        if(ch[i] >= med){
            mh = i;
            break;
        }
    }
    for(int i = 1; i <= w; i++){
        if(cw[i] >= med){
            mw = i;
            break;
        }
    }

    int ans = 0;
    for(int i = 1; i <= h; i++){
        ans += (ch[i] - ch[i-1]) * abs(mh - i);
    }
    for(int i = 1; i <= w; i++){
        ans += (cw[i] - cw[i-1]) * abs(mw - i);
    }
    cout << ans << endl;

    return 0;
}
