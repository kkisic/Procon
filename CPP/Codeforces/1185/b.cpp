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
    while(n--){
        string s, t;
        cin >> s >> t;

        vector<pair<char, int>> vs;
        rep(i, SZ(s)){
            if(vs.empty() || vs.back().first != s[i]){
                vs.emplace_back(s[i], 1);
                continue;
            }
            vs.back().second++;
        }
        vector<pair<char, int>> vt;
        rep(i, SZ(t)){
            if(vt.empty() || vt.back().first != t[i]){
                vt.emplace_back(t[i], 1);
                continue;
            }
            vt.back().second++;
        }

        if(SZ(vs) != SZ(vt)){
            cout << "NO" << endl;
            continue;
        }

        bool ok = true;
        rep(i, SZ(vs)){
            if(vs[i].first != vt[i].first){
                ok = false;
                break;
            }
            if(vs[i].second > vt[i].second){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
