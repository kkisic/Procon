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
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int l = INF;
    int r = -INF;
    int u = INF;
    int d = -INF;

    vector<vector<bool>> hanko(n, vector<bool>(m, false));
    bool white = true;
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            hanko[i][j] = (c == '#');
            if(hanko[i][j]){
                white = false;
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    }

    if(white){
        cout << 0 << endl;
        return 0;
    }

    int nh = h > 2000 ? n * 2 : h;
    int nw = w > 2000 ? m * 2 : w;

    vector<vector<int>> c(nh+1, vector<int>(nw+1));
    rep(i, n){
        rep(j, m){
            if(not hanko[i][j]){
                continue;
            }

            c[i][j] += 1;
            c[i+nh-n+1][j] -= 1;
            c[i][j+nw-m+1] -= 1;
            c[i+nh-n+1][j+nw-m+1] += 1;
        }
    }

    rep(i, nh+1){
        rep(j, nw){
            c[i][j+1] += c[i][j];
        }
    }

    rep(j, nw+1){
        rep(i, nh){
            c[i+1][j] += c[i][j];
        }
    }

    int ans = 0;
    rep(i, nh+1){
        rep(j, nw+1){
            if(c[i][j] > 0){
                ans++;
            }
        }
    }

    if(nh != h){
        ans += (h - n * 2) * (m - l);
        ans += (h - n * 2) * (r + 1);
        if(w < 2 * m){
            ans -= (h - n * 2) * (2 * m - w);
        }
    }

    if(nw != w){
        ans += (w - m * 2) * (n - u);
        ans += (w - m * 2) * (d + 1);
        if(h < 2 * n){
            ans -= (w - m * 2) * (2 * n - h);
        }
    }

    if(nh != h && nw != w){
        ans += max(0LL, h - n * 2) * max(0LL, w - m * 2);
    }

    cout << ans << endl;

    return 0;
}
