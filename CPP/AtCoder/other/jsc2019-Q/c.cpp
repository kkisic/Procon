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
    string s;
    cin >> n >> s;

    vector<int> lr(n * 2); //l:0, r:1
    rep(i, n * 2 - 1){
        if(s[i] == s[i+1]){
            lr[i+1] = (lr[i] + 1) % 2;
        }else{
            lr[i+1] = lr[i];
        }
    }

    int cnt = 0;
    rep(i, n * 2){
        if(lr[i]) cnt++;
    }

    if(s[0] == 'W' || s.back() == 'W'){
        cout << 0 << endl;
        return 0;
    }

    int r = 0;
    int l = 0;
    int ans = 1;
    for(int i = n * 2 - 1; i >= 0; i--){
        if(lr[i]){
            r++;
        }else{
            if(r - l <= 0){
                cout << 0 << endl;
                return 0;
            }
            ans *= r - l;
            ans %= MOD;
            l++;
        }
    }
    if(l != r){
        cout << 0 << endl;
        return 0;
    }

    rep(i, n){
        ans *= i + 1;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
