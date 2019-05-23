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

int n, k;
vector<int> a;

bool judge(int x){
    int len = 1;
    int cnt = 0;
    rep(i, n - 1){
        if(a[i] != a[i+1]){
            len = 1;
            continue;
        }
        len++;
        if(len > x){
            cnt++;
            len = 0;
        }
    }

    return cnt <= k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];

    int lo = 0;
    int hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(judge(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi << endl;

    return 0;
}
