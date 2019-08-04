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

    string s;
    cin >> s;
    int n = SZ(s);

    vector<int> ans(13);
    ans[0] = 1;
    rep(i, n){
        vector<int> tmp(13);
        rep(j, 13){
            if(s[i] != '?'){
                int x = j * 10 + (s[i] - '0');
                x %= 13;
                tmp[x] += ans[j];
                tmp[x] %= MOD;
                continue;
            }
            rep(k, 10){
                int x = j * 10 + k;
                x %= 13;
                tmp[x] += ans[j];
                tmp[x] %= MOD;
            }
        }
        ans = tmp;
    }
    cout << ans[5] << endl;

    return 0;
}