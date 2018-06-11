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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    int n;
    cin >> n;

    vector<int> p = prime(n);

    vector<int> sp((int)p.size());
    sp[0] = 2;
    for(int i = 1; i < (int)p.size(); i++){
        sp[i] = sp[i-1] + p[i];
    }

    vector<int> dp(n+1, -1);
    dp[0] = 0;

    rep(i, (int)p.size()){
        for(int j = n; j >= 0; j--){
            if(j < p[i] || dp[j-p[i]] == -1){
                continue;
            }
            dp[j] = max(dp[j], dp[j-p[i]]+1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
