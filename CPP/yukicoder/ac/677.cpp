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

    vector<int> ans;
    rep(i, n+1){
        rep(j, n+1){
            ans.push_back(pow(2, i) * pow(5, j));
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, (int)ans.size()){
        cout << ans[i] << endl;
    }

    return 0;
}
