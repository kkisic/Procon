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
    while(true){
        int n, m, t, p;
        cin >> n >> m >> t >> p;

        if(n == 0 && m == 0 && t == 0 && p == 0){
            break;
        }

        vector<vector<int>> a(n*2, vector<int>(m*2, 0));
        rep(i, n){
            rep(j, m){
                a[i][j] = 1;
            }
        }
        rep(i, t){
            int d, c;
            cin >> d >> c;

            if(d == 1){
                for(int j = c; j < n + c; j++){
                    int s = c*2-1;
                    if(s-j < 0){
                        break;
                    }
                    rep(k, m){
                        a[j][k] += a[s-j][k];
                        a[s-j][k] = 0;
                    }
                }
                for(int j = c; j < n + c; j++){
                    rep(k, m){
                        a[j-c][k] = a[j][k];
                        a[j][k] = 0;
                    }
                }
                n = max(c, n-c);
            }

            if(d == 2){
                for(int j = c; j < m + c; j++){
                    int s = c*2-1;
                    if(s-j < 0){
                        break;
                    }
                    rep(k, n){
                        a[k][j] += a[k][s-j];
                        a[k][s-j] = 0;
                    }
                }
                for(int j = c; j < m + c; j++){
                    rep(k, n){
                        a[k][j-c] = a[k][j];
                        a[k][j] = 0;
                    }
                }
                m = max(c, m-c);
            }
        }

        rep(i, p){
            int x, y;
            cin >> x >> y;
            cout << a[x][y] << endl;
        }
    }
    return 0;
}
