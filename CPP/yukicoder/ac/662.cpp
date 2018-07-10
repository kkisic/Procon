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
    vector<string> vs(5);
    map<string, int> ms, toI;
    rep(i, 5){
        int c;
        cin >> vs[i] >> c;
        ms.emplace(vs[i], c);
        toI.emplace(vs[i], i);
    }

    int na, nb, nc;
    vector<int> aa(5), bb(5), cc(5);
    cin >> na;
    vector<string> a(na);
    rep(i, na){
        cin >> a[i];
        aa[toI[a[i]]]++;
    }

    cin >> nb;
    vector<string> b(nb);
    rep(i, nb){
        cin >> b[i];
        bb[toI[b[i]]]++;
    }

    cin >> nc;
    vector<string> c(nc);
    rep(i, nc){
        cin >> c[i];
        cc[toI[c[i]]]++;
    }

    vector<int> ans(6);
    rep(i, 5){
        ans[i] = aa[i] * bb[i] * cc[i] * 5;
        ans[5] += ans[i] * ms[vs[i]];
    }
    cout << fixed << setprecision(3) << (double)ans[5] / (na * nb * nc) << endl;
    rep(i, 5){
        cout << ans[i] << endl;
    }

    return 0;
}
