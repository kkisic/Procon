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

    vector<int> a(n+1);
    rep(i, n) cin >> a[i+1];

    vector<int> diff(n);
    rep(i, n){
        diff[i] = a[i+1] - a[i];
    }

    vector<int> ans;
    for(int k = 1; k <= n; k++){
        bool ok = true;
        rep(i, n){
            if(diff[i] != diff[i % k]){
                ok = false;
            }
        }
        if(ok){
            ans.push_back(k);
        }
    }

    cout << ans.size() << endl;
    rep(i, (int)ans.size()-1){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;

    return 0;
}
