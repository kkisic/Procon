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
    int ga, gb, sa, sb, ba, bb;
    cin >> ga >> sa >> ba >> gb >> sb >> bb;

    int ans = 0;
    if(ga < gb && sa < sb && ba < bb){
        for(int g = 0; g * ga <= n; g++){
            for(int s = 0; s * sa <= n; s++){
                if(g * ga + s * sa > n){
                    continue;
                }
                int b = (n - g * ga - s * sa) / ba;
                int tmp = n - g * ga - s * sa - b * ba;
                tmp += g * gb + s * sb + b * bb;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(ga < gb && sa < sb){
        for(int g = 0; g * ga <= n; g++){
            for(int s = 0; s * sa <= n; s++){
                if(g * ga + s * sa > n){
                    continue;
                }
                int tmp = n - g * ga - s * sa;
                tmp += g * gb + s * sb;
                int b = tmp / bb;
                tmp -= b * bb;
                tmp += b * ba;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(ba < bb && sa < sb){
        for(int b = 0; b * ba <= n; b++){
            for(int s = 0; s * sa <= n; s++){
                if(b * ba + s * sa > n){
                    continue;
                }
                int tmp = n - b * ba - s * sa;
                tmp += b * bb + s * sb;
                int g = tmp / gb;
                tmp -= g * gb;
                tmp += g * ga;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(ga < gb && ba < bb){
        for(int g = 0; g * ga <= n; g++){
            for(int b = 0; b * ba <= n; b++){
                if(g * ga + b * ba > n){
                    continue;
                }
                int tmp = n - g * ga - b * ba;
                tmp += g * gb + b * bb;
                int s = tmp / sb;
                tmp -= s * sb;
                tmp += s * sa;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(ga < gb){
        int g = n / ga;
        int tmp = n - g * ga;
        tmp += g * gb;

        for(int s = 0; s * sb <= tmp; s++){
            int b = (tmp - s * sb) / bb;
            int tmp2 = tmp - s * sb - b * bb;
            tmp2 += s * sa + b * ba;
            ans = max(ans, tmp2);
        }
        cout << ans << endl;
        return 0;
    }
    if(ba < bb){
        int b = n / ba;
        int tmp = n - b * ba;
        tmp += b * bb;

        for(int s = 0; s * sb <= tmp; s++){
            int g = (tmp - s * sb) / gb;
            int tmp2 = tmp - s * sb - g * gb;
            tmp2 += s * sa + g * ga;
            ans = max(ans, tmp2);
        }
        cout << ans << endl;
        return 0;
    }
    if(sa < sb){
        int s = n / sa;
        int tmp = n - s * sa;
        tmp += s * sb;

        for(int b = 0; b * bb <= tmp; b++){
            int g = (tmp - b * bb) / gb;
            int tmp2 = tmp - b * bb - g * gb;
            tmp2 += b * ba + g * ga;
            ans = max(ans, tmp2);
        }
        cout << ans << endl;
        return 0;
    }

    for(int g = 0; g * gb <= n; g++){
        for(int s = 0; s * sb <= n; s++){
            if(g * gb + s * sb > n){
                continue;
            }
            int b = (n - g * gb - s * sb) / bb;
            int tmp = n - g * gb - s * sb - b * bb;
            tmp += g * ga + s * sa + b * ba;
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
