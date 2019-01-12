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

struct segment{
    int l, r, id;
};

bool compare(segment a, segment b){
    if(a.l != b.l){
        return a.l < b.l;
    }
    return a.r < b.r;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    rep(i, t){
        int n;
        cin >> n;
        vector<segment> v(n);
        rep(j, n){
            int l, r;
            cin >> l >> r;
            v[j] = {l, r, j};
        }
        sort(ALL(v), compare);

        bool ok = false;
        bool isFst = true;;
        vector<P> ans;
        ans.emplace_back(v[0].id, 1);
        int l = v[0].l;
        int r = v[0].r;
        for(int j = 1; j < n; j++){
            if(r >= v[j].l){
                ans.emplace_back(v[j].id, isFst ? 1 : 2);
                r = max(r, v[j].r);
                continue;
            }
            isFst = not isFst;
            if(not isFst){
                ok = true;
            }
            ans.emplace_back(v[j].id, isFst ? 1 : 2);
            l = v[j].l;
            r = v[j].r;
        }
        if(not ok){
            cout << -1 << endl;
            continue;
        }
        sort(ALL(ans));
        rep(j, n){
            cout << ans[j].second << " ";
        }
        cout << endl;
    }

    return 0;
}
