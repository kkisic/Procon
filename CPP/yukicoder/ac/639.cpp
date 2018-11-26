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

vector<int> dp(1e6);

int f(int x){
    if(x < 1e6){
        return dp[x];
    }

    return f(x / 3) + f(x / 5);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp = vector<int>(1e6);
    dp[0] = 1;
    for(int i = 1; i < 1e6; i++){
        dp[i] = dp[i/3] + dp[i/5];
    }
    cout << f(n) << endl;

    return 0;
}
