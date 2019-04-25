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

bool check(int x){
    while(x > 0){
        if(x % 2 == 0){
            return false;
        }
        x = x >> 1;
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    vector<int> ans;
    int cnt = 0;

    int len = 0;
    int y = x;
    while(y > 0){
        len++;
        y /= 2;
    }

    while(not check(x)){
        int a = 0;
        for(a = len - 1; a >= 0; a--){
            if((x >> a) % 2 == 0){
                break;
            }
        }
        ans.push_back(a + 1);
        x ^= (1 << (a + 1)) - 1;
        cnt++;

        if(check(x)){
            break;
        }
        x += 1;
        cnt++;
    }

    cout << cnt << endl;
    if(SZ(ans) > 0){
        rep(i, SZ(ans)){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
