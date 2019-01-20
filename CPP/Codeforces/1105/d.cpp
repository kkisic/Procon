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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e9;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> sp(p + 1);
    rep(i, p) cin >> sp[i+1];

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<P>> vp(p + 1, vector<P>());
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == '.'){
                continue;
            }
            if(c == '#'){
                a[i][j] = INF;
                continue;
            }
            vp[c-'0'].emplace_back(i, j);
            a[i][j] = (c - '0');
        }
    }

    queue<pair<P, int>> q;
    vector<int> d = {1, 0, -1, 0};
    for(int i = 1; i <= p; i++){
        for(P p : vp[i]){
            q.emplace(p, i);
        }
    }

    while(not q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if(a[x][y] != c){
            continue;
        }

        queue<pair<P, int>> pq;
        rep(k, 4){
            int nx = x + d[k];
            int ny = y + d[k^1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(a[nx][ny] != 0){
                continue;
            }
            pq.emplace(make_pair(nx, ny), sp[c]);
        }

        while(not pq.empty()){
            int xx = pq.front().first.first;
            int yy = pq.front().first.second;
            int s = pq.front().second;
            pq.pop();

            if(a[xx][yy] != 0){
                continue;
            }
            a[xx][yy] = c;
            if(s == 1){
                q.emplace(make_pair(xx, yy), c);
                continue;
            }

            rep(k, 4){
                int nx = xx + d[k];
                int ny = yy + d[k^1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }
                if(a[nx][ny] != 0){
                    continue;
                }
                pq.emplace(make_pair(nx, ny), s - 1);
            }
        }
    }

    vector<int> ans(p + 1);
    rep(i, n){
        rep(j, m){
            if(a[i][j] == INF){
                continue;
            }
            ans[a[i][j]]++;
        }
    }

    for(int i = 1; i <= p; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
