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

int n, m, a, b;

void output(vector2<char>& ans){
    cout << "YES" << endl;
    rep(i, n){
        rep(j, m){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b;

    if(n == 1 && m == 1){
        if(a > 0 || b > 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            cout << '.' << endl;
        }
        return 0;
    }

    auto ans = initvec2<char>(n, m, '.');
    bool ex = false;
    if(n % 2 && m % 2 && a >= 2 && b >= 2){
        ex = true;
    }

    if(m % 2){
        for(int i = 0; i + 1 <= n - 1 && b > 0; i += 2){
            if(ex && i == n - 3){
                continue;
            }
            ans[i][m-1] = '^';
            ans[i+1][m-1] = 'v';
            b--;
        }
    }
    if(n % 2){
        for(int i = 0; i + 1 <= m - 1 && a > 0; i += 2){
            if(ex && i == m - 3){
                continue;
            }
            ans[n-1][i] = '<';
            ans[n-1][i+1] = '>';
            a--;
        }
    }

    for(int x = 0; x + 1 < n; x += 2){
        for(int y = 0; y + 1 < m; y += 2){
            if(ex && x == n - 3 && y == m - 3){
                break;
            }
            if((not ex && a > 1) || a > 3){
                ans[x][y] = '<';
                ans[x][y+1] = '>';
                ans[x+1][y] = '<';
                ans[x+1][y+1] = '>';
                a -= 2;
                continue;
            }
            if(b > 1){
                ans[x][y] = '^';
                ans[x+1][y] = 'v';
                ans[x][y+1] = '^';
                ans[x+1][y+1] = 'v';
                b -= 2;
                continue;
            }
            if(a == 1){
                ans[x][y] = '<';
                ans[x][y+1] = '>';
                a -= 1;
                continue;
            }
            if(b == 1){
                ans[x][y] = '^';
                ans[x+1][y] = 'v';
                b--;
                continue;
            }
        }
    }

    if(ex){
        if(a == b){
            if(a > 0){
                ans[n-3][m-3] = '<';
                ans[n-3][m-2] = '>';
                a--;
            }
            if(b > 0){
                ans[n-3][m-1] = '^';
                ans[n-2][m-1] = 'v';
                b--;
            }
            if(a > 0){
                ans[n-1][m-2] = '<';
                ans[n-1][m-1] = '>';
                a--;
            }
            if(b > 0){
                ans[n-2][m-3] = '^';
                ans[n-1][m-3] = 'v';
                b--;
            }
        }else if(a > b){
            for(int i = 0; i < 3; i++){
                if(a == 0){
                    continue;
                }
                ans[n-3+i][m-3] = '<';
                ans[n-3+i][m-2] = '>';
                a--;
            }
            if(b > 0){
                ans[n-3][m-1] = '^';
                ans[n-2][m-1] = 'v';
                b--;
            }
        }else if(a < b){
            for(int i = 0; i < 3; i++){
                if(b == 0){
                    continue;
                }
                ans[n-3][m-3+i] = '^';
                ans[n-2][m-3+i] = 'v';
                b--;
            }
            if(a > 0){
                ans[n-1][m-3] = '<';
                ans[n-1][m-2] = '>';
                a--;
            }
        }
    }

    if(a > 0 || b > 0){
        cout << "NO" << endl;
        return 0;
    }
    output(ans);

    return 0;
}
