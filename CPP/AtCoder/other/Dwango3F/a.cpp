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

    int k;
    string s;
    cin >> k >> s;
    int n = s.length();

    //dp1: max dp2: min
    vector<vector<vector<int>>> dp1(n, vector<vector<int>>(n + 1, vector<int>(k+1, -INF)));
    vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n + 1, vector<int>(k+1, INF)));

    rep(i, n){
        if('0' <= s[i] && s[i] <= '9'){
            dp1[i][i+1][0] = s[i] - '0';
            dp2[i][i+1][0] = s[i] - '0';
        }
        if(k > 0){
            dp1[i][i+1][1] = 9;
            dp2[i][i+1][1] = 0;
        }
    }

    for(int len = 3; len <= n; len++){
        for(int l = 0; l <= n-len; l++){
            int r = l + len;
            for(int m = l + 1; m <= r - 1; m++){
                for(int cl = 0; cl <= k; cl++){
                    for(int cr = 0; cr <= k; cr++){
                        if(cl + cr > k){
                            continue;
                        }

                        if(s[r-1] == '+'){
                            if(dp1[l][m][cl] != -INF && dp1[m][r-1][cr] != -INF){
                                dp1[l][r][cl+cr] = max(dp1[l][r][cl+cr], dp1[l][m][cl] + dp1[m][r-1][cr]);
                            }
                            if(dp2[l][m][cl] != INF && dp2[m][r-1][cr] != INF){
                                dp2[l][r][cl+cr] = min(dp2[l][r][cl+cr], dp2[l][m][cl] + dp2[m][r-1][cr]);
                            }
                        }

                        if(s[r-1] == '-'){
                            if(dp1[l][m][cl] != -INF && dp2[m][r-1][cr] != INF){
                                dp1[l][r][cl+cr] = max(dp1[l][r][cl+cr], dp1[l][m][cl] - dp2[m][r-1][cr]);
                            }
                            if(dp2[l][m][cl] != INF && dp1[m][r-1][cr] != -INF){
                                dp2[l][r][cl+cr] = min(dp2[l][r][cl+cr], dp2[l][m][cl] - dp1[m][r-1][cr]);
                            }
                        }

                        if(cl + cr + 1 <= k){
                            if(dp1[l][m][cl] != -INF && dp1[m][r-1][cr] != -INF){
                                dp1[l][r][cl+cr+1] = max(dp1[l][r][cl+cr+1], dp1[l][m][cl] + dp1[m][r-1][cr]);
                            }
                            if(dp2[l][m][cl] != INF && dp2[m][r-1][cr] != INF){
                                dp2[l][r][cl+cr+1] = min(dp2[l][r][cl+cr+1], dp2[l][m][cl] + dp2[m][r-1][cr]);
                            }
                            if(dp1[l][m][cl] != -INF && dp2[m][r-1][cr] != INF){
                                dp1[l][r][cl+cr+1] = max(dp1[l][r][cl+cr+1], dp1[l][m][cl] - dp2[m][r-1][cr]);
                            }
                            if(dp2[l][m][cl] != INF && dp1[m][r-1][cr] != -INF){
                                dp2[l][r][cl+cr+1] = min(dp2[l][r][cl+cr+1], dp2[l][m][cl] - dp1[m][r-1][cr]);
                            }
                        }
                    }
                }
            }
        }
    }

    if(dp1[0][n][k] == -INF){
        cout << "NG" << endl;
        return 0;
    }
    cout << "OK" << endl;
    cout << dp1[0][n][k] << endl;

    return 0;
}
