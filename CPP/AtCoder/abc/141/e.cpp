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

vector<int> z_algorithm(string s){
    vector<int> z(s.size());
    z[0] = s.size();

    int i = 1, j = 0;
    while(i < (int)s.size()){
        while(i + j < (int)s.size() && s[j] == s[i+j]){
            j++;
        }
        z[i] = j;

        if(j == 0){
            i++;
            continue;
        }

        int k = 1;
        while(i + k < (int)s.size() && k + z[k] < j){
            z[i+k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i, n){
        string t = s.substr(i, n - i);
        auto za = z_algorithm(t);

        for(int j = 1; j < n - i; j++){
            ans = max(ans, min(za[j], j));
        }
    }
    cout << ans << endl;

    return 0;
}
