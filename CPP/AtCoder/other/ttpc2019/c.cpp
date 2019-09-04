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

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int cnt = 0;
    int sum = 0;
    rep(i, n){
        if(a[i] != -1){
            sum ^= a[i];
        }else{
            cnt++;
        }
    }

    int y = x ^ sum;
    if(cnt == 0){
        if(y == 0){
            rep(i, n){
                cout << a[i] << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    if(y <= x){
        bool used = false;
        rep(i, n){
            if(a[i] != -1){
                cout << a[i] << " ";
            }else if(not used){
                cout << y << " ";
                used = true;
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
        return 0;
    }

    if(sum <= x && y > x){
        if(cnt < 2){
            cout << -1 << endl;
            return 0;
        }
        int used = 0;
        rep(i, n){
            if(a[i] != -1){
                cout << a[i] << " ";
            }else if(used == 0){
                cout << sum << " ";
                used++;
            }else if(used == 1){
                cout << x << " ";
                used++;
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
