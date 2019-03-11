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

    vector<int> ans = {0, 0, 0, 0, 0, 1, 2, 2, 3, 4};

    int h, w;
    cin >> h >> w;
    auto a = initVec2<int>(h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];

    int maxi = -1;
    bool isZero = true;
    bool five = false;
    rep(i, h){
        rep(j, w){
            if(a[i][j] == 0){
                continue;
            }
            isZero = false;
            if(a[i][j] == 5){
                five = true;
            }
            maxi = max(maxi, a[i][j]);
        }
    }

    if(isZero){
        cout << "Yes 0" << endl;
        return 0;
    }
    if(not five){
        cout << "No" << endl;
        return 0;
    }

    if(min(h, w) == 1){
        vector<int> x;
        int m = 0;
        rep(i, h){
            rep(j, w){
                if(a[i][j] == 5 && m != 0){
                    x.push_back(m);
                    m = 0;
                }
                if(a[i][j] < 5){
                    continue;
                }
                m = max(m, a[i][j]);
            }
        }
        if(m != 0){
            x.push_back(m);
        }

        if(x.size() <= 1){
            cout << "Yes " << ans[maxi] << endl;
            return 0;
        }

        vector<int> s(SZ(x)), t(SZ(x));
        s[0] = x[0];
        for(int i = 1; i < SZ(x); i++){
            s[i] = max(x[i], s[i-1]);
        }
        t[SZ(x)-1] = x.back();
        for(int i = SZ(x) - 2; i >= 0; i--){
            t[i] = max(x[i], t[i+1]);
        }

        int mini = INF;
        rep(i, SZ(x) - 1){
            mini = min(mini, ans[s[i]] + ans[t[i+1]] - 1);
        }
        cout << "Yes " << mini << endl;
    }else{
        cout << "Yes " << ans[maxi] << endl;
    }

    return 0;
}
