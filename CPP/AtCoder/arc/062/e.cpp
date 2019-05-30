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

typedef tuple<int, int, int, int> tup;

tup rotate(tup& t){
    int a, b, c, d;
    tie(a, b, c, d) = t;
    return make_tuple(b, c, d, a);
}

bool check(tup& s, tup& t, int& c){
    if(s == t){
        c--;
    }
    t = rotate(t);
    if(s == t){
        c--;
    }
    t = rotate(t);
    if(s == t){
        c--;
    }
    t = rotate(t);
    if(s == t){
        c--;
    }
    return c;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tup> v(n);
    map<tup, int> m;
    rep(i, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        tup t = make_tuple(a, b, c, d);
        v[i] = t;

        m[t]++;
        t = rotate(t);
        m[t]++;
        t = rotate(t);
        m[t]++;
        t = rotate(t);
        m[t]++;
    }

    int ans = 0;
    rep(i, n){
        tup t = v[i];
        m[t]--;
        t = rotate(t);
        m[t]--;
        t = rotate(t);
        m[t]--;
        t = rotate(t);
        m[t]--;

        int a, b, c, d;
        tie(a, b, c, d) = t;
        for(int j = i + 1; j < n; j++){
            tup t1 = v[j];
            rep(k, 4){
                int e, f, g, h;
                tie(e, f, g, h) = t1;
                t1 = rotate(t1);

                tup t2 = make_tuple(b, a, h, g);
                tup t3 = make_tuple(c, b, g, f);
                tup t4 = make_tuple(d, c, f, e);
                tup t5 = make_tuple(a, d, e, h);

                int c2 = m[t2];
                int c3 = m[t3];
                int c4 = m[t4];
                int c5 = m[t5];

                check(t1, t2, c2);
                check(t1, t3, c3);
                check(t2, t3, c3);
                check(t1, t4, c4);
                check(t2, t4, c4);
                check(t3, t4, c4);
                check(t1, t5, c5);
                check(t2, t5, c5);
                check(t3, t5, c5);
                check(t4, t5, c5);

                if(c2 <= 0 || c3 <= 0 || c4 <= 0 || c5 <= 0){
                    continue;
                }
                ans += c2 * c3 * c4 * c5;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
