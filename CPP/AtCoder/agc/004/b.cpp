#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n, x;

int solve(const vector<vector<int>>& b, int k){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[(n+i-k)%n][k];
    }
    ans += x * k;

    return ans;
}

signed main(){
    cin >> n >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> b(n, vector<int>(n));
    rep(i, n) b[i][0] = a[i];

    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            b[i][j] = min(b[i][(n+j-1) % n], a[(i+j)%n]);
        }
    }

    int ans = INF;
    rep(k, n){
        int tmp = solve(b, k);
        if(tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
