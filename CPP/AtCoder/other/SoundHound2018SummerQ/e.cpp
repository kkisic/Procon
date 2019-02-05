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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto edge = initVec2<P>(n + 1, 0);
    rep(i, m){
        int u, v, s;
        cin >> u >> v >> s;
        edge[u].emplace_back(v, s);
        edge[v].emplace_back(u, s);
    }

    vector<P> cond(n + 1);
    //[mini, maxi]
    int maxi = INF;
    int mini = 1;
    int x = 0;
    stack<pair<int, P>> st;
    st.emplace(1, make_pair(0, 1));
    while(not st.empty()){
        int v = st.top().first;
        P p = st.top().second;
        st.pop();

        if(cond[v].second != 0){
            if(cond[v].second == p.second){
                if(cond[v].first != p.first){
                    cout << 0 << endl;
                    return 0;
                }
                continue;
            }else{
                if(cond[v].second > 0){
                    x = (p.first - cond[v].first) / 2;
                }else{
                    x = (cond[v].first - p.first) / 2;
                }
                break;
            }
        }
        cond[v] = p;
        if(cond[v].second > 0){
            mini = max(mini, 1 - cond[v].first);
        }else{
            maxi = min(maxi, cond[v].first - 1);
        }

        for(P q : edge[v]){
            int u = q.first;
            int w = q.second;
            st.emplace(u, make_pair(w - p.first, -p.second));
        }
    }

    if(x == 0){
        if(maxi - mini >= 0){
            cout << maxi - mini + 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }

    vector<int> used(n + 1);
    stack<P> sst;
    sst.emplace(1, x);
    while(not sst.empty()){
        int v = sst.top().first;
        int num = sst.top().second;
        sst.pop();

        if(used[v] != 0){
            if(used[v] != num){
                cout << 0 << endl;
                return 0;
            }
            continue;
        }
        used[v] = num;

        for(P p : edge[v]){
            int u = p.first;
            int w = p.second;
            if(w - num <= 0){
                cout << 0 << endl;
                return 0;
            }
            sst.emplace(u, w - num);
        }
    }
    cout << 1 << endl;

    return 0;
}
