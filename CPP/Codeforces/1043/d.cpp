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

const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    rep(i, m){
        rep(j, n){
            scanf("%lld", &a[i][j]);
        }
    }

    vector<vector<int>> next(m, vector<int>(n+1, -1));
    rep(i, m){
        rep(j, n-1){
            next[i][a[i][j]] = a[i][j+1];
        }
    }

    int idx = 0;
    int ans = 0;
    int len = 0;
    bool ok = true;
    while(idx < n){
        int x = a[0][idx++];

        for(int i = 1; i < m; i++){
            if(next[0][x] != next[i][x]){
                ok = false;
            }
        }
        len++;

        if(not ok){
            ans += (1 + len) * len / 2;
            len = 0;
            ok = true;
        }
    }
    ans += (1 + len) * len / 2;

    cout << ans << endl;

    return 0;
}
