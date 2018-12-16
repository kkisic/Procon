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
const int MOD = 998244353;

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    rep(i, t){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edge(n + 1, vector<int>());
        rep(j, m){
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        bool ng = false;
        vector<int> c(n+1);
        int color = 0;
        queue<P> que;
        for(int j = 1; j <= n; j++){
            if(c[j] != 0){
                continue;
            }
            que.emplace(j, ++color);
            while(not que.empty()){
                int v = que.front().first;
                int col = que.front().second;
                que.pop();

                if(c[v] != 0){
                    if(c[v] == col){
                        continue;
                    }
                    ng = true;
                    break;
                }
                c[v] = col;

                for(int u : edge[v]){
                    que.emplace(u, -col);
                }
            }

            if(ng){
                break;
            }
        }
        if(ng){
            cout << 0 << endl;
            continue;
        }

        int ans = 1;
        map<int, int> mm;
        for(int j = 1; j <= n; j++){
            if(mm.find(c[j]) == mm.end()){
                mm[c[j]] = 0;
                mm[-c[j]] = 0;
            }
            mm[c[j]]++;
        }

        for(int j = 1; j <= color; j++){
            int tmp;
            if(mm[-j]){
                tmp = powM(2, mm[j]) + powM(2, mm[-j]);
                tmp %= MOD;
            }else{
                tmp = 3;
            }
            ans *= tmp;
            ans %= MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
