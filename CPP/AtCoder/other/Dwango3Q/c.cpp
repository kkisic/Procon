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
    vector<int> a(n), g(5);
    rep(i, n){
        cin >> a[i];
        g[a[i]]++;
    }

    int ans = 0;
    ans += g[4];
    int tmp = min(g[1], g[3]);
    ans += g[3];
    g[1] -= tmp;
    ans += g[2] / 2;
    g[2] %= 2;

    if(g[2] != 0){
        ans += 1;
        if(g[1] > 2){
            g[1] -= 2;
        }else{
            g[1] = 0;
        }
    }
    ans += g[1] / 4;
    if(g[1] % 4 != 0){
        ans++;
    }
    cout << ans << endl;

    return 0;
}
