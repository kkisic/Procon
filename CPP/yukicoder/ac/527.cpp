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
    int n, vv;
    cin >> n;
    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];
    cin >> vv;

    vector<int> dp(100001);
    rep(i, n){
        for(int j = 100000; j >= 0; j--){
            if(j < w[i]){
                continue;
            }
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    int sum = 0;
    rep(i, n){
        sum += v[i];
    }

    int min;
    rep(i, 100001){
        if(dp[i] == vv){
            min = i;
            break;
        }
    }

    int max;
    for(int i = 100000; i >= 0; i--){
        if(dp[i] == vv){
            max = i;
            break;
        }
    }

    if(min == 0){
        cout << 1 << endl;
    }else{
        cout << min << endl;
    }
    if(sum == vv){
        cout << "inf" << endl;
    }else{
        cout << max << endl;
    }

    return 0;
}
