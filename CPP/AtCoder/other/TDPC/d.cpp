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
    int n, d;
    cin >> n >> d;

    //factorization
    vector<int> p = {2, 3, 5};
    vector<int> x(3);
    rep(i, 3){
        while(d % p[i] == 0){
            x[i]++;
            d /= p[i];
        }
    }
    if(d != 1){
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }

    vector<vector<vector<double>>> dp(70, vector<vector<double>>(70, vector<double>(70)));
    dp[0][0][0] = 1;
    vector<int> p2 = {0, 1, 0, 2, 0, 1};
    vector<int> p3 = {0, 0, 1, 0, 0, 1};
    vector<int> p5 = {0, 0, 0, 0, 1, 0};
    rep(i, n){
        vector<vector<vector<double>>> tmp(70, vector<vector<double>>(70, vector<double>(70)));
        rep(j, 65){
            rep(k, 65){
                rep(l, 65){
                    if(dp[j][k][l] == 0){
                        continue;
                    }
                    rep(m, 6){
                        int nj = min(x[0], j + p2[m]);
                        int nk = min(x[1], k + p3[m]);
                        int nl = min(x[2], l + p5[m]);
                        tmp[nj][nk][nl] += dp[j][k][l] / 6.0;
                    }
                }
            }
        }
        dp = tmp;
    }

    cout << fixed << setprecision(10) << dp[x[0]][x[1]][x[2]] << endl;

    return 0;
}
