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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int ans = 0;

        vector<int> v(n);
        rep(i, n) v[i] = i + 1;

        rep(i, 9){
            vector<int> tmp;
            vector<int> s, t;

            rep(j, SZ(v)){
                if(j % 2 == 0){
                    s.push_back(v[j]);
                }else{
                    t.push_back(v[j]);
                }
            }

            cout << SZ(s) << " " << SZ(t);
            rep(j, SZ(s)){
                cout << " " << s[j];
                tmp.push_back(s[j]);
            }
            rep(j, SZ(t)){
                cout << " " << t[j];
                tmp.push_back(t[j]);
            }
            cout << endl;

            int len;
            cin >> len;
            ans = max(ans, len);
            v = tmp;
        }
        cout << -1 << " " << ans << endl;
    }

    return 0;
}
