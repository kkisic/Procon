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
    string s;
    cin >> n >> k >> s;

    vector<int> a = {0};
    vector<int> b = {s[0] - '0'};
    int now = s[0] - '0';
    rep(i, n){
        if(now == s[i] - '0'){
            a.back()++;
            continue;
        }
        now ^= 1;
        b.push_back(now);
        a.push_back(1);
    }

    vector<int> ss(SZ(a) + 1);
    rep(i, SZ(a)) ss[i+1] = a[i] + ss[i];

    int ans = 0;
    for(int i = 0; i < SZ(ss); i++){
        int len = k * 2;
        if(b[i] == 1){
            len++;
        }
        ans = max(ans, ss[min(i+len, SZ(ss) - 1)] - ss[i]);
    }
    cout << ans << endl;

    return 0;
}
