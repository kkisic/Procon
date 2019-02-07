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

bool compare(P a, P b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    int q = 0;
    int i = 0;
    while(s[i] != '/'){
        p *= 10;
        p += s[i++] - '0';
    }
    i++;
    while(i < SZ(s)){
        q *= 10;
        q += s[i++] - '0';
    }
    double pq = (double)p / (double)q;

    auto a = initVec2<int>(n, n - 1);
    rep(i, n){
        int k = 0;
        rep(j, n){
            if(i == j){
                int x;
                cin >> x;
                continue;
            }
            cin >> a[i][k++];
        }
    }

    vector<int> cnt(n);
    rep(i, n){
        rep(j, n - 1){
            cnt[i] += a[i][j];
        }
    }

    vector<P> x(n);
    rep(i, n){
        x[i] = {cnt[i], i};
    }
    sort(ALL(x), compare);

    vector2<int> b(n);
    rep(i, n){
        b[i] = a[x[i].second];
    }

    vector3<double> dp1 = initVec3<double>(n, n, n);
    rep(i, n){
        dp1[i][0][0] = 1.0;
        rep(j, n - 1){
            for(int k = 0; k <= j; k++){
                if(b[i][j] == 1){
                    dp1[i][j+1][k+1] += dp1[i][j][k] * pq;
                    dp1[i][j+1][k] += dp1[i][j][k] * (1.0 - pq);
                }else{
                    dp1[i][j+1][k+1] += dp1[i][j][k] * (1.0 - pq);
                    dp1[i][j+1][k] += dp1[i][j][k] * pq;
                }
            }
        }
    }

    vector<double> dp2(n);
    dp2[0] = 1.0;
    for(int i = n - 1; i >= 0; i--){
        rep(j, n - 1) dp2[j+1] += dp2[j];

        vector<double> tmp(n);
        rep(j, n){
            if(i < n - 1 && x[i].first > x[i+1].first && x[i].second > x[i+1].second){
                if(j == 0){
                    continue;
                }
                tmp[j] = dp2[j-1] * dp1[i][n-1][j];
            }else{
                tmp[j] = dp2[j] * dp1[i][n-1][j];
            }
        }
        dp2 = tmp;
    }

    double ans = 0;
    rep(i, n){
        ans += dp2[i];
    }
    cout << fixed << setprecision(16) << ans << endl;

    return 0;
}
