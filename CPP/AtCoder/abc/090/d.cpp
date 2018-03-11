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
    int n, k;
    cin >> n >> k;

    if(k == 0){
        cout << n * n << endl;
        return 0;
    }

    int ans = n * k;
    for(int i = k + 1; i <= n; i++){
        int div = n / i;
        int mod = n % i;
        ans += k * div + min(mod, k - 1);
    }

    cout << n * n - ans << endl;

    return 0;
}
