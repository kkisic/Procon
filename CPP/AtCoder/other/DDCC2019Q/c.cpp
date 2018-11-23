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

    vector<int> x(n+1, 1);
    x[0] = 0;
    for(int i = 1; i <= n; i++){
        rep(j, 10) {
            x[i] *= i;
            x[i] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i * i <= n; i++){
        for(int j = i; i * j <= n; j++){
            int tmp = x[i] * x[j] % MOD;
            tmp = (tmp + MOD - x[i-1] * x[j] % MOD) % MOD;
            tmp = (tmp + MOD - x[i] * x[j-1] % MOD) % MOD;
            tmp = (tmp + x[i-1] * x[j-1] % MOD) % MOD;
            if(i != j){
                tmp = tmp * 2 % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
