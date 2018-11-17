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
const int LEN = 2540;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<map<int, int>> st(n+1, map<int, int>());
    rep(i, m){
        int a, b, l;
        cin >> a >> b >> l;

        if(st[a].find(l) == st[a].end()){
            st[a][l] = 0;
        }
        if(st[b].find(l) == st[b].end()){
            st[b][l] = 0;
        }
        st[a][l]++;
        st[b][l]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(P p : st[i]){
            if(p.first > LEN / 2){
                break;
            }
            if(st[i].find(LEN - p.first) == st[i].end()){
                continue;
            }
            if(p.first == LEN / 2){
                ans += p.second * (p.second - 1) / 2;
                continue;
            }
            ans += p.second * st[i][LEN-p.first];
        }
    }
    cout << ans << endl;

    return 0;
}
