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

    vector<int> a(n+2);
    rep(i, n) cin >> a[i+1];
    a[n+1] = 1001;

    vector<P> range;

    int head = 0;
    for(int i = 0; i <= n; i++){
        if(a[i] + 1 == a[i+1]){
            continue;
        }

        range.emplace_back(head, i);
        head = i+1;
    }

    range.emplace_back(head, n+1);

    int ans = 0;
    for(P p : range){
        int tmp = p.second - p.first - 1;
        if(tmp > ans){
            ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
