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

vector<int> cycle(vector<int>& pre, int s){
    vector<int> ans;
    while(s != -1){
        ans.push_back(s);
        s = pre[s];
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto edge = initVec2<int>(n, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
    }

    vector<int> ans;
    int len = INF;
    rep(i, n){
        vector<int> pre(n, INF);
        queue<P> q;
        q.emplace(i, -1);
        while(not q.empty()){
            int v = q.front().first;
            int p = q.front().second;
            q.pop();

            if(pre[v] != INF){
                continue;
            }
            pre[v] = p;

            bool ok = false;
            for(int u : edge[v]){
                if(u == i){
                    ok = true;
                }
                q.emplace(u, v);
            }

            if(ok){
                auto tmp = cycle(pre, v);
                if(len > SZ(tmp)){
                    len = SZ(tmp);
                    ans = tmp;
                }
                break;
            }
        }
    }

    if(len == INF){
        cout << -1 << endl;
    }else{
        cout << len << endl;
        rep(i, len){
            cout << ans[i] + 1 << endl;
        }
    }

    return 0;
}
