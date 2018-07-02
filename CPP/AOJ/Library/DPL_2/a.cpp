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
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edge(v, vector<int>(v, INF));
    rep(i, e){
        int s, t, d;
        cin >> s >> t >> d;
        edge[s][t] = d;
    }

    vector<vector<int>> cost(1 << v, vector<int>(v, INF));
    //始点は0
    cost[1][0] = 0;
    for(int s = 0; s < (1 << v); s++){
        rep(i, v){
            if(s != 0 && (s >> i) % 2 == 0){
                continue;
            }
            rep(j, v){
                if((s >> j) % 2 == 1 || edge[i][j] == INF){
                    continue;
                }
                if(cost[s | (1 << j)][j] > cost[s][i] + edge[i][j]){
                    cost[s | (1 << j)][j] = cost[s][i] + edge[i][j];
                }
            }
        }
    }

    int ans = INF;
    rep(i, v){
        if(ans > cost[(1 << v) - 1][i] + edge[i][0]){
            ans = cost[(1 << v) - 1][i] + edge[i][0];
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}
