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
const int MOD = 998244353;

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp1(202);
    vector<int> dp0(202);

    if(a[0] != -1){
        dp0[a[0]] = 1;
        dp0[a[0]+1] = MOD-1;
    }else{
        dp0[1] = 1;
        dp0[201] = MOD-1;
    }

    for(int i = 0; i < n - 1; i++){
        //imos
        for(int j = 1; j <= 200; j++){
            dp0[j+1] = (dp0[j+1] + dp0[j]) % MOD;
            dp1[j+1] = (dp1[j+1] + dp1[j]) % MOD;
        }

        vector<int> tmp1(202);
        vector<int> tmp0(202);

        for(int j = 1; j <= 200; j++){
            if(dp1[j] == 0){
                continue;
            }

            if(a[i+1] == -1){
                tmp1[1] = (tmp1[1] + dp1[j]) % MOD;
                tmp1[j+1] = (tmp1[j+1] - dp1[j] + MOD) % MOD;
                tmp0[j+1] = (tmp0[j+1] + dp1[j]) % MOD;
                tmp0[201] = (tmp0[201] - dp1[j] + MOD) % MOD;
                continue;
            }

            if(j >= a[i+1]){
                tmp1[a[i+1]] = (tmp1[a[i+1]] + dp1[j]) % MOD;
                tmp1[a[i+1]+1] = (tmp1[a[i+1]+1] - dp1[j] + MOD) % MOD;
            }

            if(j < a[i+1]){
                tmp0[a[i+1]] = (tmp0[a[i+1]] + dp1[j]) % MOD;
                tmp0[a[i+1]+1] = (tmp0[a[i+1]+1] - dp1[j] + MOD) % MOD;
            }
        }
        for(int j = 1; j <= 200; j++){
            if(dp0[j] == 0){
                continue;
            }

            if(a[i+1] == -1){
                tmp1[j] = (tmp1[j] + dp0[j]) % MOD;
                tmp1[j+1] = (tmp1[j+1] - dp0[j] + MOD) % MOD;
                tmp0[j+1] = (tmp0[j+1] + dp0[j]) % MOD;
                tmp0[201] = (tmp0[201] - dp0[j] + MOD) % MOD;
                continue;
            }

            if(j == a[i+1]){
                tmp1[a[i+1]] = (tmp1[a[i+1]] + dp0[j]) % MOD;
                tmp1[a[i+1]+1] = (tmp1[a[i+1]+1] - dp0[j] + MOD) % MOD;
            }

            if(j < a[i+1]){
                tmp0[a[i+1]] = (tmp0[a[i+1]] + dp0[j]) % MOD;
                tmp0[a[i+1]+1] = (tmp0[a[i+1]+1] - dp0[j] + MOD) % MOD;
            }
        }

        dp1 = tmp1;
        dp0 = tmp0;
    }

    //imos
    for(int j = 1; j <= 200; j++){
        dp0[j+1] = (dp0[j+1] + dp0[j]) % MOD;
        dp1[j+1] = (dp1[j+1] + dp1[j]) % MOD;
    }

    int ans = 0;
    for(int i = 1; i <= 200; i++){
        ans = (ans + dp1[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
