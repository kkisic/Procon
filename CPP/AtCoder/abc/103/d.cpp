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
    int n, m;
    cin >> n >> m;
    vector<P> c;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        c.emplace_back(a, b);
    }
    sort(c.begin(), c.end());

    vector<P> ans;
    int cc = 0;
    rep(i, m){
        if(i == 0){
            ans.push_back(c[i]);
            cc++;
            continue;
        }

        if(ans[cc-1].second > c[i].first){
            ans[cc-1].first = max(ans[cc-1].first, c[i].first);
            ans[cc-1].second = min(ans[cc-1].second, c[i].second);
            continue;
        }
        ans.push_back(c[i]);
        cc++;
    }
    cout << cc << endl;

    return 0;
}
