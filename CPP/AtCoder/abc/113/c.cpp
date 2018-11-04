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

    map<int, vector<P>> mm;
    rep(i, m){
        int p, y;
        cin >> p >> y;

        if(mm.find(p) == mm.end()){
            mm[p] = vector<P>();
        }
        mm[p].emplace_back(y, i);
    }

    vector<P> ans(m);
    for(pair<int, vector<P>> p : mm){
        sort(p.second.begin(), p.second.end());

        int num = 0;
        for(P pp : p.second){
            ans[pp.second] = {p.first, num++};
        }
    }

    rep(i, m){
        printf("%06lld%06lld\n", ans[i].first, ans[i].second+1);
    }

    return 0;
}
