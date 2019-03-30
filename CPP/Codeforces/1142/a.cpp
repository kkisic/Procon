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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;

    vector<int> s = {1 + a, n * k + 1 - a};
    int maxi = 0;
    int mini = INF;
    for(int x = 1; x <= n * k; x += k){
        vector<int> t = {(x - 1 + b) % (n * k) + 1, (x - 1 + n * k - b) % (n * k) + 1};

        rep(i, 2){
            rep(j, 2){
                int l = abs(s[i] - t[j]);
                if(l == 0){
                    l = n * k;
                }
                int g = gcd(n * k, l);
                maxi = max(maxi, n * k / g);
                mini = min(mini, n * k / g);

                if(l == n * k){
                    continue;
                }
                l = n * k - l;
                g = gcd(n * k, l);
                maxi = max(maxi, n * k / g);
                mini = min(mini, n * k / g);
            }
        }
    }
    cout << mini << " " << maxi << endl;

    return 0;
}
