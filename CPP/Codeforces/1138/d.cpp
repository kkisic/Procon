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

class RollingHash{
    private:
        const static int mod1 = 999999937LL;
        const static int mod2 = 1000000007LL;
        const static int base = 9973;

    public:
        int n;
        string s;
        vector<int> hash1, hash2, pow1, pow2;

        RollingHash(string s)
            :n(s.length()), s(s), hash1(n+1), hash2(n+1), pow1(n+1, 1), pow2(n+1, 1){
                for(int i = 0; i < n; i++){
                    hash1[i+1] = (hash1[i] + s[i]) * base % mod1;
                    hash2[i+1] = (hash2[i] + s[i]) * base % mod2;
                    pow1[i+1] = pow1[i] * base % mod1;
                    pow2[i+1] = pow2[i] * base % mod2;
                }

            }

        //[l, r)
        P hash(int l, int r){
            int t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
            int t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
            return make_pair(t1, t2);
        }

        bool compare(int l1, int r1, int l2, int r2){
            return hash(l1, r1) == hash(l2, r2);
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = SZ(s);
    int a = 0;
    rep(i, n){
        if(s[i] == '1'){
            a++;
        }
    }

    int m = SZ(t);
    int b = 0;
    rep(i, m){
        if(t[i] == '1'){
            b++;
        }
    }

    if(n < m || a < b){
        cout << s << endl;
        return 0;
    }

    RollingHash rh(t);
    int maxi = 0;
    for(int k = 1; k < m; k++){
        if(rh.compare(0, k, m - k, m)){
            maxi = k;
        }
    }

    string ans(n, '0');
    int i;
    for(i = 0; i < m; i++){
        if(n - i == a){
            break;
        }
        ans[i] = t[i];
        if(ans[i] == '1'){
            a--;
        }
    }
    for(; i < m; i++){
        ans[i] = '1';
        a--;
    }
    for(i = m; i < n; i++){
        if(a == 0){
            continue;
        }
        if(n - i == a){
            break;
        }
        ans[i] = t[maxi+(i-m)%(m-maxi)];
        if(ans[i] == '1'){
            a--;
        }
    }
    for(; i < n; i++){
        ans[i] = '1';
    }
    cout << ans << endl;

    return 0;
}
