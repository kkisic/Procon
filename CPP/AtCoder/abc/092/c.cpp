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

int solve(const vector<int>& a, int i, int ans){
    return ans - abs(a[i+1] - a[i]) - abs(a[i] - a[i-1]) + abs(a[i+1] - a[i-1]);
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n+2);
    rep(i, n) cin >> a[i+1];

    int ans = 0;
    rep(i, (int)a.size()-1){
        ans += abs(a[i+1] - a[i]);
    }

    for(int i = 1; i <= n; i++){
        cout << solve(a, i, ans) << endl;
    }
    return 0;
}
