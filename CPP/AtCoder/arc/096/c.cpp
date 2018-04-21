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
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int aa = min(a, c * 2);
    int bb = min(b, c * 2);
    int ab = min(a + b, c * 2);

    int ans = 0;
    if(x < y){
        ans += x * ab;
        ans += (y - x) * bb;
    }else{
        ans += y * ab;
        ans += (x - y) * aa;
    }
    cout << ans << endl;

    return 0;
}
