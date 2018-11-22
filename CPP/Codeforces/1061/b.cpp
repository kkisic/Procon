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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int sum = 0;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }

    sort(ALL(a));
    int need = 0;
    int high = a[n-1];
    for(int i = n - 1; i >= 0; i--){
        if(high <= a[i]){
            high--;
            need++;
            continue;
        }
        need += high - a[i] + 1;
        high = a[i] - 1;
    }
    if(high > 1){
        need += high;
    }

    cout << sum - need << endl;

    return 0;
}
