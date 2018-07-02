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
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    int h1 = n / 2;
    int h2 = n - h1;
    vector<P> a;
    rep(i, (1 << h2)){
        int ww = 0;
        int vv = 0;
        rep(j, h2){
            if((i >> j) % 2 == 0){
                continue;
            }
            ww += w[h1 + j];
            vv += v[h1 + j];
        }
        a.emplace_back(ww, vv);
    }
    sort(a.begin(), a.end());

    vector<P> s;
    int max = 0;
    rep(i, (int)a.size()){
        if(i < (int)a.size()-1 && a[i].first == a[i+1].first){
            continue;
        }

        if(a[i].second <= max){
            continue;
        }
        max = a[i].second;
        s.push_back(a[i]);
    }

    int ans = 0;
    rep(i, (1 << h1)){
        int ww = 0;
        int vv = 0;
        rep(j, h1){
            if((i >> j) % 2 == 0){
                continue;
            }
            ww += w[j];
            vv += v[j];
        }

        int lo = 0;
        int hi = s.size();
        while(hi - lo > 1){
            int m = (hi + lo) / 2;
            if(s[m].first <= W - ww){
                lo = m;
            }else{
                hi = m;
            }
        }
        if(ww + s[lo].first <= W && ans < s[lo].second + vv){
            ans = s[lo].second + vv;
        }
    }
    cout << ans << endl;

    return 0;
}
