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

    int q;
    cin >> q;

    vector<int> s(26, 1);
    for(int i = 1; i < 25; i++){
        int x = (1 << (i + 1)) - 1;
        for(int j = 2; j * j <= x; j++){
            if(x % j != 0){
                continue;
            }
            s[i+1] = max(s[i+1], x / j);
        }
    }

    rep(i, q){
        int a;
        cin >> a;
        int x = a;
        int ok = false;
        int len = 0;
        while(x != 0){
            if(x % 2 == 0){
                ok = true;
            }
            x /= 2;
            len++;
        }

        if(ok){
            cout << (1 << len) - 1 << endl;
        }else{
            cout << s[len] << endl;
        }
    }

    return 0;
}
