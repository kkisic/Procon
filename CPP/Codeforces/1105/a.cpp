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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = INF;
    int t = 0;
    for(int i = 1; i <= 100; i++){
        int tmp = 0;
        rep(j, n){
            if(abs(a[j] - i) > 1){
                tmp += min(abs(a[j] - i - 1), abs(a[j] - i + 1));
            }

        }
        if(tmp < ans){
            ans = tmp;
            t = i;
        }
    }
    cout << t << " " << ans << endl;

    return 0;
}
