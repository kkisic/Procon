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

bool compare(const pair<P, int>& a, const pair<P, int>& b){
    int x = b.first.first - a.first.first;
    int y = b.first.second - a.first.second;

    if(x != y){
        return x < y;
    }
    return a.second < b.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<P, int>> s(n);
    vector<P> ps(n+1);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        s[i] = {{x, y}, i+1};
        ps[i+1] = {x, y};
    }

    vector<P> nopair(m);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        nopair[i] = {u, v};
    }

    sort(s.begin(), s.end(), compare);
    vector<int> fst(n+1), snd(n+1);
    rep(i, n){
        fst[i+1] = fst[i] + s[i].first.first;
        snd[i+1] = snd[i] + s[i].first.second;
    }

    vector<int> ans(n+1);
    rep(i, n){
        int id = s[i].second;
        if(id == 0){
            continue;
        }

        ans[id] = snd[i] + fst[n] - fst[i+1];
        ans[id] += ps[id].first * i + ps[id].second * (n - i - 1);
    }

    rep(i, m){
        int u = nopair[i].first;
        int v = nopair[i].second;

        int score = min(ps[u].first + ps[v].second, ps[u].second + ps[v].first);
        ans[u] -= score;
        ans[v] -= score;
    }

    for(int i = 1; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n] << endl;

    return 0;
}
