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

int n, q;
string s;
vector<pair<char, char>> query;

bool check(int pos, char c){
    rep(i, q){
        if(s[pos] != query[i].first){
            continue;
        }
        if(query[i].second == 'L'){
            if(pos == 0){
                return c == 'L';
            }
            pos--;
        }else{
            if(pos == n - 1){
                return c == 'R';
            }
            pos++;
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s;

    query = vector<pair<char, char>>(q);
    rep(i, q){
        char t, d;
        cin >> t >> d;
        query[i] = {t, d};
    }

    int lo, hi;

    lo = -1;
    hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;

        if(check(mid, 'L')){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    int l = lo;

    lo = -1;
    hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;

        if(check(mid, 'R')){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    int r = hi;

    cout << n - (l + 1 + n - r) << endl;

    return 0;
}
