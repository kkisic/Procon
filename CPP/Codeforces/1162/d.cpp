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

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    vector<set<int>> vs(n, set<int>());
    rep(i, m){
        cin >> a[i] >> b[i];
        if(a[i] > b[i]){
            swap(a[i], b[i]);
        }
        a[i]--;
        b[i]--;
        vs[a[i]].insert(b[i]);
    }

    for(int i = 1; i * i <= n; i++){
        if(n % i != 0){
            continue;
        }

        bool ok;
        ok = true;
        rep(j, m){
            int na = (a[j] + i) % n;
            int nb = (b[j] + i) % n;
            if(na > nb){
                swap(na, nb);
            }
            if(vs[na].find(nb) == vs[na].end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }

        ok = true;
        rep(j, m){
            int na = (a[j] + n - i) % n;
            int nb = (b[j] + n - i) % n;
            if(na > nb){
                swap(na, nb);
            }
            if(vs[na].find(nb) == vs[na].end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }

        int x = n / i;
        if(x == n){
            continue;
        }
        ok = true;
        rep(j, m){
            int na = (a[j] + x) % n;
            int nb = (b[j] + x) % n;
            if(na > nb){
                swap(na, nb);
            }
            if(vs[na].find(nb) == vs[na].end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }

        ok = true;
        rep(j, m){
            int na = (a[j] + n - x) % n;
            int nb = (b[j] + n - x) % n;
            if(na > nb){
                swap(na, nb);
            }
            if(vs[na].find(nb) == vs[na].end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
