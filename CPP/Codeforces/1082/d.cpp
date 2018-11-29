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
    int sum = 0;
    vector<int> a(n);
    vector<P> ver(n);
    rep(i, n){
        int a;
        cin >> a;
        sum += a;
        ver[i] = {a, i+1};
    }
    sort(ALL(ver), greater<P>());

    int need = (n - 1) * 2;

    if(sum < need){
        cout << "NO" << endl;
        return 0;
    }

    queue<int> que;
    vector<P> edge;
    int v = ver[0].second;
    rep(i, ver[0].first - 1){
        que.push(v);
    }
    bool isOne = false;
    for(int i = 1; i < n; i++){
        if(isOne){
            if(que.empty()){
                cout << "NO" << endl;
                return 0;
            }
            edge.emplace_back(que.front(), ver[i].second);
            que.pop();
            continue;
        }
        if(ver[i].first == 1){
            isOne = true;
        }
        edge.emplace_back(v, ver[i].second);
        v = ver[i].second;
        rep(j, ver[i].first - 2){
            que.push(v);
        }
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for(P p : edge){
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    vector<int> dep1(n+1, -1);
    queue<P> qq;
    qq.emplace(1, 0);
    while(not qq.empty()){
        int v = qq.front().first;
        int d = qq.front().second;
        qq.pop();

        if(dep1[v] != -1){
            continue;
        }
        dep1[v] = d;
        for(int u : graph[v]){
            if(dep1[u] == -1){
                qq.emplace(u, d+1);
            }
        }
    }
    int start = 0;
    rep(i, n+1){
        if(dep1[start] < dep1[i]){
            start = i;
        }
    }

    vector<int> dep2(n+1, -1);
    qq.emplace(start, 0);
    while(not qq.empty()){
        int v = qq.front().first;
        int d = qq.front().second;
        qq.pop();

        if(dep2[v] != -1){
            continue;
        }
        dep2[v] = d;
        for(int u : graph[v]){
            if(dep2[u] == -1){
                qq.emplace(u, d+1);
            }
        }
    }
    int len = 0;
    rep(i, n){
        len = max(len, dep2[i+1]);
    }

    cout << "YES " << len << endl;
    cout << SZ(edge) << endl;
    for(P p : edge){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
