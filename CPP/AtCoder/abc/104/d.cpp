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
    string s;
    cin >> s;

    int n = s.length();
    vector<int> a(n+1), c(n+1), q(n+1);
    a[0] = c[0] = q[0] = 0;
    rep(i, n){
        a[i+1] = a[i];
        c[i+1] = c[i];
        q[i+1] = q[i];
        if(s[i] == 'A'){
            a[i+1]++;
        }
        if(s[i] == 'C'){
            c[i+1]++;
        }
        if(s[i] == '?'){
            q[i+1]++;
        }
    }

    int ans = 0;
    rep(i, n){
        if(s[i] != 'B' && s[i] != '?'){
            continue;
        }
        int qq = q[n];
        if(s[i] == '?'){
            qq--;
        }

        int aa = a[i];
        int cc = c[n] - c[i+1];

        int tmp = aa * cc % MOD * powM(3, qq)  % MOD;
        if(qq > 0){
            tmp = (tmp + aa * (q[n] - q[i+1]) % MOD * powM(3, qq - 1) % MOD) % MOD;
            tmp = (tmp + q[i] * cc % MOD * powM(3, qq - 1) % MOD) % MOD;
        }
        if(qq > 1){
            tmp = (tmp + q[i] * (q[n] - q[i+1]) % MOD * powM(3, qq - 2) % MOD) % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;

    return 0;
}
