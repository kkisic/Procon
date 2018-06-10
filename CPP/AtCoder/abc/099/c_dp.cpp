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

signed main(){
    int n;
    cin >> n;

    vector<int> v;
    v.push_back(1);
    int a = 6;
    while(a <= n){
        v.push_back(a);
        a *= 6;
    }
    a = 9;
    while(a <= n){
        v.push_back(a);
        a *= 9;
    }
    sort(v.begin(), v.end());

    vector<int> dp(n+1, INF);
    dp[0] = 0;

    rep(i, (int)v.size()){
        for(int j = v[i]; j <= n; j++){
            dp[j] = min(dp[j - v[i]]+1, dp[j]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
