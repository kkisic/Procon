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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;

    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    int n, z;
    cin >> n >> z;

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] = gcd(a[i], z);
    }
    cout << endl;

    int ans = 1;
    rep(i, n){
        ans = a[i] / gcd(ans, a[i]) * ans;
    }
    cout << ans << endl;

    return 0;
}
