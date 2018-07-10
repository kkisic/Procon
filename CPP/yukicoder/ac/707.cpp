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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int h, w;
    cin >> h >> w;

    vector<vector<int>> p(h+1, vector<int>(w+1));
    rep(i, h) rep(j, w){
        char c;
        cin >> c;
        p[i+1][j+1] = c - '0';
    }

    double min = 1e15;
    for(int i = 0; i <= h+1; i++){
        for(int j = 0; j <= w+1; j++){
            if(i != 0 && i != h+1 && j != 0 && j != w+1){
                continue;
            }
            double tmp = 0;
            rep(k, h+1){
                rep(l, w+1){
                    if(p[k][l] == 0){
                        continue;
                    }
                    tmp += sqrt(pow(i-k, 2) + pow(j-l, 2));
                }
            }
            if(tmp < min){
                min = tmp;
            }
        }
    }
    cout << fixed << setprecision(6) << min << endl;

    return 0;
}
