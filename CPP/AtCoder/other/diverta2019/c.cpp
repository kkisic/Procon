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
    cin >> n;

    int ab = 0;
    int a = 0;
    int b = 0;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int ans = 0;
    rep(i, n){
        rep(j, SZ(s[i]) - 1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B'){
                ans++;
            }
        }

        if(s[i].front() == 'B' && s[i].back() == 'A'){
            ab++;
            continue;
        }
        if(s[i].front() == 'B'){
            b++;
        }
        if(s[i].back() == 'A'){
            a++;
        }
    }

    if(ab > 0){
        ans += ab - 1;
        if(a > 0){
            a--;
            ans++;
        }
        if(b > 0){
            b--;
            ans++;
        }
    }

    cout << ans + min(a, b) << endl;

    return 0;
}
