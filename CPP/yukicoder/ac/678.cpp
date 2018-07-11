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

signed main(){
    int n, lb, rb;
    cin >> n >> lb >> rb;

    vector<tuple<int, int, int, int>> e;
    rep(i, n){
        int l, u, r, d;
        cin >> l >> u >> r >> d;

        e.emplace_back(-d, max(0LL, l), min(r, rb), i);
    }
    sort(e.begin(), e.end());

    vector<bool> used(rb+1, false);
    vector<int> hit(n);
    rep(i, n){
        int l = get<1>(e[i]);
        int r = get<2>(e[i]);

        if(r < lb || rb < l){
            continue;
        }

        for(int j = max(l, lb); j <= min(r, rb); j++){
            if(not used[j]){
                hit[get<3>(e[i])] = 1;
            }
            used[j] = true;
        }
    }

    rep(i, n){
        cout << hit[i] << endl;
    }

    return 0;
}
