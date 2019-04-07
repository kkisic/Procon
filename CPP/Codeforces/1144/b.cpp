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

    vector<int> odd, even;
    rep(i, n){
        int x;
        cin >> x;
        if(x % 2){
            odd.push_back(x);
        }else{
            even.push_back(x);
        }
    }
    sort(ALL(odd), greater<int>());
    sort(ALL(even), greater<int>());

    if(abs(SZ(odd) - SZ(even)) <= 1){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    if(SZ(odd) > SZ(even)){
        for(int i = SZ(even) + 1; i < SZ(odd); i++){
            ans += odd[i];
        }
    }else{
        for(int i = SZ(odd) + 1; i < SZ(even); i++){
            ans += even[i];
        }
    }
    cout << ans << endl;

    return 0;
}
