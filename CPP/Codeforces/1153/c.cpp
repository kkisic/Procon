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
    string s;
    cin >> n >> s;

    if(n % 2){
        cout << ":(" << endl;
        return 0;
    }

    int l = 0;
    int r = 0;
    rep(i, n){
        if(s[i] == '('){
            l++;
        }
        if(s[i] == ')'){
            r++;
        }
    }

    if(l > n / 2 || r > n / 2){
        cout << ":(" << endl;
        return 0;
    }

    l = n / 2 - l;
    rep(i, n){
        if(l > 0 && s[i] == '?'){
            s[i] = '(';
            l--;
            continue;
        }
        if(s[i] == '?'){
            s[i] = ')';
        }
    }

    int open = 0;
    rep(i, n){
        if(s[i] == '('){
            open++;
        }else{
            open--;
        }
        if(i != n - 1 && open == 0){
            cout << ":(" << endl;
            return 0;
        }
        if(open < 0){
            cout << ":(" << endl;
            return 0;
        }
    }

    cout << s << endl;

    return 0;
}
