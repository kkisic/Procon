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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int n;
bool check(vector2<int>& a, int s, int t, int x){
    rep(i, n / x){
        if(a[i][s] != a[i][t]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<string> vs(n);
    rep(i, n) cin >> vs[i];

    vector<int> cnt;
    int i = 0;
    int j = 0;
    while(i < n){
        cnt.push_back(0);
        while(j < n && vs[i] == vs[j]){
            cnt.back()++;
            j++;
        }
        i = j;
    }

    int g = cnt[0];
    rep(i, SZ(cnt)){
        g = gcd(g, cnt[i]);
    }

    auto a = initVec2<int>(n / g, n);
    rep(i, n / g){
        rep(j, n / 4){
            char c = vs[i*g][j];
            int x = 0;
            if('0' <= c && c <= '9'){
                x = c - '0';
            }else{
                x = c - 'A' + 10;
            }
            rep(k, 4){
                a[i][j*4+k] = (x >> (3 - k)) % 2;
            }
        }
    }

    i = j = 0;
    cnt = vector<int>();
    while(i < n){
        cnt.push_back(0);
        while(j < n && check(a, i, j, g)){
            cnt.back()++;
            j++;
        }
        i = j;
    }

    rep(i, SZ(cnt)){
        g = gcd(g, cnt[i]);
    }
    cout << g << endl;
    return 0;
}
