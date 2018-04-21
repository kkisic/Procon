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
    int n, c;
    cin >> n >> c;

    vector<int> x(n+1), v(n+1), rx(n+1), rv(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> v[i];
        rx[n+1-i] = c - x[i];
        rv[n+1-i] = v[i];
    }

    vector<int> s(n+1), rs(n+1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + v[i];
        rs[i] = rs[i-1] + rv[i];
    }

    vector<int> maxV(n+1), maxRV(n+1);
    for(int i = 1; i <= n; i++){
        maxV[i] = max(maxV[i-1], s[i] - x[i]);
        maxRV[i] = max(maxRV[i-1], rs[i] - rx[i]);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int tmp = maxV[i];
        tmp += max((int)0, maxRV[n-i] - x[i]);
        if(ans < tmp){
            ans = tmp;
        }
    }

    for(int i = 0; i <= n; i++){
        int tmp = maxRV[i];
        tmp += max((int)0, maxV[n-i] - rx[i]);
        if(ans < tmp){
            ans = tmp;
        }
    }

    cout << ans << endl;
    return 0;
}
