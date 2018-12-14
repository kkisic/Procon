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

    int n, k, l;
    cin >> n >> k >> l;

    vector<int> da = {1, 0, 0, 1, 1, 0, 1};
    vector<int> db = {0, 1, 0, 1, 0, 1, 1};
    vector<int> dc = {0, 0, 1, 0, 1, 1, 1};

    vector<vector<vector<int>>> dp(1 << k, vector<vector<int>>(1 << k, vector<int>(1 << k)));
    dp[0][0][0] = 1;
    rep(i, n){
        vector<vector<vector<int>>> tmp(1 << k, vector<vector<int>>(1 << k, vector<int>(1 << k)));

        rep(s, 1LL << (3 * k)){
            int t = s;
            int a = t % (1 << k);
            t /= 1 << k;
            int b = t % (1 << k);
            t /= 1 << k;
            int c = t;

            if(dp[a][b][c] == 0){
                continue;
            }

            int sa, sb, sc;
            sa = sb = sc = 0;

            rep(j, k){
                if(j == 0){
                    continue;
                }
                sa += (a >> j) % 2;
                sb += (b >> j) % 2;
                sc += (c >> j) % 2;
            }

            rep(j, 7){
                int na = sa + da[j];
                int nb = sb + db[j];
                int nc = sc + dc[j];
                if(na > l || nb > l || nc > l){
                    continue;
                }
                int aa = a >> 1 | da[j] << (k - 1);
                int bb = b >> 1 | db[j] << (k - 1);
                int cc = c >> 1 | dc[j] << (k - 1);
                tmp[aa][bb][cc] += dp[a][b][c];
                tmp[aa][bb][cc] %= MOD;
            }
        }
        dp = tmp;
    }

    int ans = 0;
    rep(s, 1LL << (3 * k)){
        int t = s;
        int a = t % (1 << k);
        t /= 1 << k;
        int b = t % (1 << k);
        t /= 1 << k;
        int c = t;

        ans += dp[a][b][c];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
