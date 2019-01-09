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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int c[4] = {};
    int sum = 0;
    rep(i, n){
        c[a[i]]++;
        sum += a[i];
    }

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                if(i + j + k != 0){
                    dp[i][j][k] += (double)n / (double)(i + j + k);
                    if(i < n && j > 0){
                        dp[i+1][j-1][k] += dp[i][j][k] * (double)(i + 1) / (double)(i + j + k);
                    }
                    if(j < n && k > 0){
                        dp[i][j+1][k-1] += dp[i][j][k] * (double)(j + 1) / (double)(i + j + k);
                    }
                }
                if(k < n){
                    dp[i][j][k+1] += dp[i][j][k] * (double)(k + 1) / (double)(i + j + k + 1);
                }
            }
        }
    }
    cout << fixed << setprecision(10) << dp[c[3]][c[2]][c[1]] << endl;

    return 0;
}
