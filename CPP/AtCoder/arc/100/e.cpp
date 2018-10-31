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

    vector<int> a(1 << n);
    rep(i, 1 << n) cin >> a[i];

    vector<P> fst(1 << n, {a[0], 0}), snd(1 << n);
    for(int s = 1; s < (1 << n); s++){
        if(fst[s].first <= a[s]){
            snd[s] = fst[s];
            fst[s] = {a[s], s};
        }else if(snd[s].first <= a[s]){
            snd[s] = {a[s], s};
        }

        rep(j, n){
            if((s >> j) % 2 == 1){
                continue;
            }
            int t = s | (1 << j);

            if(fst[t] < fst[s] && fst[t].second != fst[s].second){
                snd[t] = fst[t];
                fst[t] = fst[s];
            }else if(snd[t] < fst[s] && fst[t].second != fst[s].second){
                snd[t] = fst[s];
            }

            if(snd[t] < snd[s] && snd[t].second != snd[s].second){
                snd[t] = snd[s];
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < (1 << n); i++){
        ans = max(ans, fst[i].first + snd[i].first);
        cout << ans << endl;
    }

    return 0;
}
