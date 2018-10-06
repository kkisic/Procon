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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n, vector<bool>(m, false));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == '#'){
                a[i][j] = true;
            }
        }
    }

    vector<vector<bool>> b(n, vector<bool>(m, false));
    rep(i, n-2){
        rep(j, m-2){
            int ok = true;

            rep(k, 3){
                rep(l, 3){
                    if(k == 1 && l == 1){
                        continue;
                    }

                    if(not a[i+k][j+l]){
                        ok = false;
                    }
                }
            }

            if(not ok){
                continue;
            }
            rep(k, 3){
                rep(l, 3){
                    if(k == 1 && l == 1){
                        continue;
                    }
                    b[i+k][j+l] = true;
                }
            }
        }
    }

    bool ans = true;
    rep(i, n){
        rep(j, m){
            if(a[i][j] != b[i][j]){
                ans = false;
            }
        }
    }

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
