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

    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> edge(n, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }

    vector<vector<bool>> dpR(3, vector<bool>(n, false));
    vector<vector<bool>> dpB(2, vector<bool>(n, false));
    rep(i, n){
        if(s[i] == 'R'){
            dpR[0][i] = true;
        }
        if(s[i] == 'B'){
            dpB[0][i] = true;
        }
    }

    //どれか一つRに行ける
    rep(v, n){
        for(int u : edge[v]){
            if(dpR[0][u]){
                dpR[1][v] = true;
            }
            if(dpB[0][u]){
                dpB[1][v] = true;
            }
        }
    }

    //全部R(B)に行ける点に行ける
    rep(v, n){
        bool ok = true;
        for(int u : edge[v]){
            if(not dpR[1][u]){
                ok = false;
            }
        }
        if(ok){
            dpR[2][v] = true;
        }
    }

    if(k % 2){
        rep(i, n){
            if(dpB[1][i]){
                cout << "First" << endl;
            }else{
                cout << "Second" << endl;
            }
        }
    }else{
        rep(i, n){
            if(dpR[2][i]){
                cout << "Second" << endl;
            }else{
                cout << "First" << endl;
            }
        }
    }

    return 0;
}
