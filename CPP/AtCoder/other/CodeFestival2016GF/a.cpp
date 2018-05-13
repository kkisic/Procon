#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

    vector<int> x(2*n);
    map<int, bool> y;
    rep(i, n){
        cin >> x[i];
        y[x[i]] = false;
    }
    rep(i, n){
        cin >> x[n+i];
        y[x[n+i]] = true;
    }
    sort(x.begin(), x.end());

    stack<int> a, b;
    int ans = 1;
    rep(i, 2*n){
        if(y[x[i]]){
            if(not a.empty()){
                ans *= a.size();
                ans %= MOD;
                a.pop();
                continue;
            }
            b.push(x[i]);
        }else{
            if(not b.empty()){
                ans *= b.size();
                ans %= MOD;
                b.pop();
                continue;
            }
            a.push(x[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
