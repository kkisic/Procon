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

struct env{
    int s, t, d, w;
};

bool compare(env& a, env& b){
    return a.s < b.s;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<env> ve(k);
    rep(i, k){
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        ve[i] = {s, t, d, w};
    }
    sort(ALL(ve), compare);

    auto f = [](env& a, env& b){
        if(a.w != b.w){
            return a.w < b.w;
        }
        return a.d < b.d;
    };
    priority_queue<env, vector<env>, decltype(f)> pq(f);
    int cnt = 0;
    env inf = {INF, 0, 0, 0};
    vector<env> best(n + 1, inf);
    for(int i = 1; i <= n; i++){
        while(cnt < k && ve[cnt].s <= i){
            pq.push(ve[cnt++]);
        }
        while(not pq.empty() && pq.top().t < i){
            pq.pop();
        }
        if(pq.empty()){
            best[i] = {0, 0, i, 0};
            continue;
        }
        best[i] = pq.top();
    }

    auto dp = initVec2<int>(n + 2, m + 2, INF);
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[best[i].d+1][j] = min(dp[best[i].d+1][j], dp[i][j] + best[i].w);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        }
    }

    int ans = INF;
    rep(i, m + 1){
        ans = min(ans, dp[n+1][i]);
    }
    cout << ans << endl;

    return 0;
}
