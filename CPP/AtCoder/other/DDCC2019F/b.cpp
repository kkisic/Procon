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

    int n, k, r;
    cin >> n >> k >> r;
    int sum = (1 + n - k) * (n - k) / 2;

    if(sum < r){
        cout << "No Luck" << endl;
        return 0;
    }

    vector<vector<int>> pos(n + 1, vector<int>());
    vector<bool> moved(n + 1, false);
    for(int i = n; i >= 1; i--){
        if(sum == r){
            break;
        }
        int diff = sum - r;
        int x = min(i - k, diff);
        pos[i-k-x].push_back(i);
        moved[i] = true;
        sum -= x;
    }

    vector<int> ans;
    for(int i = 0; i <= n; i++){
        if(moved[i]){
            continue;
        }
        if(i > 0){
            ans.push_back(i);
        }
        for(int x : pos[i]){
            ans.push_back(x);
        }
    }
    reverse(ALL(ans));

    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
