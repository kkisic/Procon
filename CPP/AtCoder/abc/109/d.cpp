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
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    vector<tuple<int, int, int, int>> ans;
    rep(i, h){
        rep(j, w){
            if(a[i][j] % 2 == 0){
                continue;
            }

            if(i == h - 1 && j == w - 1){
                continue;
            }

            if(j == w - 1){
                ans.emplace_back(i+1, j+1, i+2, j+1);
                a[i+1][j]++;
                continue;
            }

            ans.emplace_back(i+1, j+1, i+1, j+2);
            a[i][j+1]++;
        }
    }

    cout << ans.size() << endl;
    for(tuple<int, int, int, int> t : ans){
        cout << get<0>(t) << " ";
        cout << get<1>(t) << " ";
        cout << get<2>(t) << " ";
        cout << get<3>(t) << endl;
    }

    return 0;
}
