#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n, c;
    cin >> n >> c;

    vector<vector<int>> d(c+1, vector<int>(c+1));
    rep(i, c){
        rep(j, c){
            cin >> d[i+1][j+1];
        }
    }
    vector<vector<int>> cc(n+1, vector<int>(n+1));
    rep(i, n){
        rep(j, n){
            cin >> cc[i+1][j+1];
        }
    }

    vector<vector<int>> t(3, vector<int>(c+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            t[(i+j)%3][cc[i][j]]++;
        }
    }

    int ans = INF;
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c; j++){
            for(int k = 1; k <= c; k++){
                if(i == j || j == k || k == i){
                    continue;
                }

                int tmp = 0;
                for(int x = 1; x <= c; x++){
                    tmp += d[x][i] * t[0][x];
                    tmp += d[x][j] * t[1][x];
                    tmp += d[x][k] * t[2][x];
                }
                if(ans > tmp){
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
