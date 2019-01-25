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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

bool check(vector<int>& p, vector<int>& c, int m){
    vector<int> cnt(SZ(p));
    rep(i, SZ(p)){
        for(int x = p[i]; x <= m; x *= p[i]){
            cnt[i] += m / x;
        }
    }

    rep(i, SZ(p)){
        if(c[i] > cnt[i]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p = prime(1e4);
    vector<int> cnt(SZ(p));

    int m = n;
    rep(i, SZ(p)){
        if(m % p[i] == 0){
            while(m % p[i] == 0){
                cnt[i]++;
                m /= p[i];
            }
        }
    }
    if(m != 1){
        p.push_back(m);
        cnt.push_back(1);
    }

    int lo = 0;
    int hi = 1e8;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(check(p, cnt, mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi << endl;

    return 0;
}
