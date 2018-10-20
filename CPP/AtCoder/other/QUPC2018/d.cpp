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

bool compare(const P& a, const P& b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first > b.first;
}

signed main(){
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> t(n+1);
    rep(i, n) cin >> t[i+1];

    vector<vector<P>> go(n+1, vector<P>());
    vector<vector<P>> back(n+1, vector<P>());
    rep(i, m){
        int x, a;
        cin >> x >> a;
        go[x].emplace_back(a, a + t[x]);
    }
    rep(i, l){
        int y, b;
        cin >> y >> b;
        back[y].emplace_back(b, b + t[y]);
    }

    vector<P> job;
    for(int i = 1; i <= n; i++){
        sort(go[i].begin(), go[i].end());
        sort(back[i].begin(), back[i].end());

        int l = 0;
        for(int r = 0; r < (int)back[i].size(); r++){
            while(l < (int)go[i].size() && back[i][r].first > go[i][l].second){
                job.emplace_back(go[i][l].first, back[i][r].second);
                l++;
            }
        }
    }
    sort(job.begin(), job.end(), compare);

    int now = -1;
    int ans = 0;
    rep(i, (int)job.size()){
        if(job[i].first > now){
            ans += 2;
            now = job[i].second;
        }
    }

    for(int i = 1; i <= n; i++){
        rep(j, (int)go[i].size()){
            if(go[i][j].first > now){
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
