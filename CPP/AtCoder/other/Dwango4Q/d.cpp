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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int n;
vector<int> x, dependent, task;
vector2<int> edge;

void dfs(int v){
    for(int u : edge[v]){
        dfs(u);
        dependent[v] |= dependent[u];
        dependent[v] |= 1 << u;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    x = vector<int>(n);
    rep(i, n) cin >> x[i];
    edge = initVec2<int>(n, 0);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        edge[a-1].push_back(i);
    }


    //頂点vを頂点とする部分木の子の集合
    dependent = vector<int>(n);
    dfs(0);

    //ある集合sが実行済且つ不要な物を削除した時のディスク使用量
    task = vector<int>(1 << n, INF);
    task[0] = 0;
    rep(s, 1 << n){
        if(task[s] == INF){
            continue;
        }
        rep(v, n){
            if((s >> v) % 2){
                continue;
            }
            bool ok = true;
            int sum = 0; //削除するものの和
            for(int u : edge[v]){
                if((s >> u) % 2 == 0){
                    ok = false;
                }
                sum += x[u];
            }
            if(ok){
                task[s|(1<<v)] = task[s] + x[v] - sum;
            }
        }
    }

    //集合sを全て実行済にするまでの最大ディスク使用量の最小値
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    rep(s, 1 << n){
        if(dp[s] == INF){
            continue;
        }
        rep(v, n){
            if((s >> v) % 2){
                continue;
            }
            bool ok = true;
            for(int u : edge[v]){
                if((s >> u) % 2 == 0){
                    ok = false;
                }
            }
            if(ok){
                //sまでの最小値とs+{v}を実行済にする際の使用量のうち,
                //大きい方でdp[s+{v}]の最小値を更新する.
                //s+{v}の実行時は,
                //x[v]:vの使用量
                //taxk[dependent[v]]:vが依存するタスクが実行済である時の使用量
                //task[s^dependent[v]]:それ以外のタスクが実行済である時の使用量
                //の和が総使用量となる.
                dp[s^(1<<v)] = min(dp[s^(1<<v)], max(dp[s], task[dependent[v]] + x[v] + task[s^dependent[v]]));
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;

    return 0;
}
