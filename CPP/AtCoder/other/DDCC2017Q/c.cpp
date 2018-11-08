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

    int n, c;
    cin >> n >> c;

    vector<int> l(n);
    rep(i, n) cin >> l[i];

    sort(l.begin(), l.end());
    int head = 0;
    int last = n - 1;
    int ans = 0;
    while(head <= last){
        if(l[head] + l[last--] + 1 <= c){
            head++;
            ans++;
            continue;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}
