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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    int b, c, d;
    cin >> b >> c >> d;

    b %= MOD;
    c %= MOD;

    if(c == 1){
        d %= MOD;
        cout << b * d % MOD << endl;
        return 0;
    }

    int ans = b * c % MOD * ((MOD + powM(c, d) - 1) % MOD) % MOD * powM(c - 1, MOD - 2) % MOD;
    cout << ans << endl;

    return 0;
}
