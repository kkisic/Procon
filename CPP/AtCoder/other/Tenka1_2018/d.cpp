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
    int n;
    cin >> n;

    int sum = 0;
    int x = 0;
    while(sum < n){
        sum += ++x;
    }

    if(sum != n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    vector<vector<int>> ans(x+1, vector<int>());

    int y = 1;
    for(int s = 1; s <= x; s++){
        for(int t = 0; t < s; t++){
            ans[s].push_back(y);
            ans[t].push_back(y);
            y++;
        }
    }

    cout << x+1 << endl;
    rep(i, x+1){
        int m = ans[i].size();
        cout << m << " ";
        rep(j, m-1){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m-1] << endl;
    }

    return 0;
}
