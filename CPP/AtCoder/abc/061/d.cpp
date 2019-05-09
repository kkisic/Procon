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

vector<int> dist;
vector<bool> neg;
void bellman_ford(vector<vector<P>>& edge, int n, int s){
    dist = vector<int>(n + 1, INF);
    neg = vector<bool>(n + 1, false);
    dist[s] = 0;
    for(int i = 0; i < n; i++){
        for(int v = 1; v <= n; v++){
            for(int k = 0; k < (int)edge[v].size(); k++){
                P p = edge[v][k];
                if(neg[v]){
                    neg[p.first] = true;
                }
                if(dist[v] != INF && dist[p.first] > dist[v] + p.second){
                    dist[p.first] = dist[v] + p.second;
                    if(i == n - 1) neg[p.first] = true;
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto edge = initVec2<P>(n + 1, 0);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, -c);
    }

    bellman_ford(edge, n, 1);
    if(neg[n]){
        cout << "inf" << endl;
    }else{
        cout << -dist[n] << endl;
    }

    return 0;
}
