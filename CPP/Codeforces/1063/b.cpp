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
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;

    vector<vector<bool>> a(n, vector<bool>(m, false));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == '.'){
                a[i][j] = true;
            }
        }
    }

    vector<vector<P>> mark(n, vector<P>(m, {-1, -1}));
    vector<int> d = {1, 0, -1, 0};
    P init = {-1, -1};
    queue<pair<P, P>> que;
    que.push({{r-1, c-1}, {x, y}});
    while(not que.empty()){
        int s = que.front().first.first;
        int t = que.front().first.second;
        int le = que.front().second.first;
        int ri = que.front().second.second;
        que.pop();

        if(le < 0 || ri < 0){
            continue;
        }

        //cout << s << " " << t << endl;
        if(mark[s][t] != init && mark[s][t].first + mark[s][t].second >= le + ri){
            continue;
        }
        mark[s][t] = {le, ri};

        rep(i, 4){
            int nx = s + d[i];
            int ny = t + d[i^1];

            if(nx < 0 || n <= nx || ny < 0 || m <= ny || not a[nx][ny]){
                continue;
            }

            if(i == 1){
                que.push({{nx, ny}, {le, ri - 1}});
            }else if(i == 3){
                que.push({{nx, ny}, {le - 1, ri}});
            }else{
                que.push({{nx, ny}, {le, ri}});
            }
        }
    }

    //cout << endl;
    int ans = 0;
    rep(i, n){
        rep(j, m){
            if(mark[i][j] != init){
                ans++;
                //cout << '+';
                continue;
            }
            //cout << (a[i][j] ? '.' : '*');
        }
        //cout << endl;
    }
    cout << ans << endl;


    return 0;
}
