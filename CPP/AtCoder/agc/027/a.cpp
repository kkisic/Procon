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

signed main(){
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    int sum = 0;
    rep(i, n){
        if(sum + a[i] <= x){
            ans++;
        }
        sum += a[i];
    }
    if(sum < x){
        ans--;
    }
    cout << ans << endl;

    return 0;
}
