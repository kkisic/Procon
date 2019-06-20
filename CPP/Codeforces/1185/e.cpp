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

typedef tuple<int, int, int, int> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        auto a = initVec2<int>(n, m, -INF);
        rep(i, n){
            rep(j, m){
                char c;
                cin >> c;
                if(c != '.'){
                    a[i][j] = c - 'a';
                }
            }
        }

        stack<tup> ans;
        bool ng = false;
        bool fst = true;
        for(int c = 25; c >= 0; c--){
            int x1, y1, x2, y2;
            x1 = y1 = x2 = y2 = -1;

            rep(i, n) rep(j, m){
                if(a[i][j] != c){
                    continue;
                }
                if(x1 == -1){
                    x1 = i;
                    y1 = j;
                }
                x2 = i;
                y2 = j;
            }

            if(x1 == -1){
                if(not fst){
                    ans.push(ans.top());
                }
                continue;
            }
            fst = false;

            if(x1 != x2 && y1 != y2){
                ng = true;
            }
            ans.emplace(x1, y1, x2, y2);
        }

        queue<tup> que;
        auto b = initVec2<int>(n, m, -INF);
        int x = 0;
        while(not ans.empty()){
            int x1, y1, x2, y2;
            tie(x1, y1, x2, y2) = ans.top();
            que.push(ans.top());
            ans.pop();

            if(x1 == x2){
                for(int i = y1; i <= y2; i++){
                    b[x1][i] = x;
                }
            }
            if(y1 == y2){
                for(int i = x1; i <= x2; i++){
                    b[i][y1] = x;
                }
            }
            x++;
        }

        rep(i, n){
            rep(j, m){
                if(a[i][j] != b[i][j]){
                    ng = true;
                }
            }
        }
        if(ng){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << SZ(que) << endl;
        while(not que.empty()){
            int a, b, c, d;
            tie(a, b, c, d) = que.front();
            que.pop();
            cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
        }
    }

    return 0;
}
