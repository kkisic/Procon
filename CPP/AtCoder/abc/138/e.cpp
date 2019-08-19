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

    string s, t;
    cin >> s >> t;
    int n = SZ(s);

    vector<int> pos(26, -1);
    for(int i = n - 1; i >= 0; i--){
        pos[s[i]-'a'] = i;
    }

    auto nxt = initVec2<int>(n, 26, -1);
    for(int i = n - 1; i >= 0; i--){
        rep(j, 26){
            nxt[i][j] = pos[j];
        }
        pos[s[i]-'a'] = i;
    }

    vector<int> ans;
    ans.push_back(pos[t[0]-'a']);
    int i = 1;
    while(i < SZ(t) && ans.back() != -1){
        ans.push_back(nxt[ans.back()][t[i++]-'a']);
    }

    if(ans.back() == -1){
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    rep(i, SZ(ans) - 1){
        if(ans[i] >= ans[i+1]){
            cnt++;
        }
    }
    cout << n * cnt + ans.back() + 1 << endl;

    return 0;
}
