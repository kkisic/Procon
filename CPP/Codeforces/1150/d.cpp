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

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    auto nxt = initVec2<int>(n + 1, 26, INF);
    for(int i = n - 1; i >= 0; i--){
        rep(j, 26){
            nxt[i][j] = nxt[i+1][j];
        }
        nxt[i][s[i]-'a'] = i;
    }

    auto p = initVec2<int>(3, 0);
    auto dp = initVec3<int>(251, 251, 251, INF);
    dp[0][0][0] = 0;

    while(q--){
        char a;
        int x;
        cin >> a >> x;
        x--;

        if(a == '+'){
            char c;
            cin >> c;
            p[x].push_back(c - 'a');

            int k = SZ(p[x]);
            if(x == 0){
                rep(i, SZ(p[1]) + 1) rep(j, SZ(p[2]) + 1){
                    dp[k][i][j] = INF;
                    if(dp[k-1][i][j] != INF) dp[k][i][j] = min(dp[k][i][j], nxt[dp[k-1][i][j]][p[0][k-1]] + 1);
                    if(i > 0 && dp[k][i-1][j] != INF) dp[k][i][j] = min(dp[k][i][j], nxt[dp[k][i-1][j]][p[1][i-1]] + 1);
                    if(j > 0 && dp[k][i][j-1] != INF) dp[k][i][j] = min(dp[k][i][j], nxt[dp[k][i][j-1]][p[2][j-1]] + 1);
                }
            }
            if(x == 1){
                rep(i, SZ(p[0]) + 1) rep(j, SZ(p[2]) + 1){
                    dp[i][k][j] = INF;
                    if(dp[i][k-1][j] != INF) dp[i][k][j] = min(dp[i][k][j], nxt[dp[i][k-1][j]][p[1][k-1]] + 1);
                    if(i > 0 && dp[i-1][k][j] != INF) dp[i][k][j] = min(dp[i][k][j], nxt[dp[i-1][k][j]][p[0][i-1]] + 1);
                    if(j > 0 && dp[i][k][j-1] != INF) dp[i][k][j] = min(dp[i][k][j], nxt[dp[i][k][j-1]][p[2][j-1]] + 1);
                }
            }
            if(x == 2){
                rep(i, SZ(p[0]) + 1) rep(j, SZ(p[1]) + 1){
                    dp[i][j][k] = INF;
                    if(dp[i][j][k-1] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][p[2][k-1]] + 1);
                    if(i > 0 && dp[i-1][j][k] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][p[0][i-1]] + 1);
                    if(j > 0 && dp[i][j-1][k] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][p[1][j-1]] + 1);
                }
            }
        }else{
            p[x].pop_back();
        }

        if(dp[SZ(p[0])][SZ(p[1])][SZ(p[2])] != INF){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
