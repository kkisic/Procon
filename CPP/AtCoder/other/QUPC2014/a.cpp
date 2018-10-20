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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<vector<int>> e(c, vector<int>(a));
    rep(i, c){
        rep(j, a){
            cin >> e[i][j];
        }
    }

    for(int i = 100; i >= 0; i--){
        int sum = 0;
        rep(j, c){
            int cnt = 0;
            rep(k, a){
                if(e[j][k] >= i){
                    cnt++;
                }
            }
            if(cnt >= b){
                sum++;
            }
        }
        if(sum >= d){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
