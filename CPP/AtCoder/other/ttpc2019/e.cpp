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

    if(n % 2 == 0){
        cout << "No" << endl;
        return 0;
    }

    auto ans = initVec2<int>(n, n);
    rep(i, n){
        ans[i][0] = n * (i + 1);
    }
    for(int i = 1; i < n; i++){
        ans[0][i] = i;
        for(int j = 1; j < n; j++){
            ans[i][j] = i + n * j;
        }
    }

    cout << "Yes" << endl;
    rep(i, n){
        rep(j, n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
