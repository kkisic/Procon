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

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    set<int> s;
    vector<int> ans;
    int j = 0;
    rep(i, n){
        if(s.find(b[i]) != s.end()){
            ans.push_back(0);
            continue;
        }

        int step = 0;
        while(j < n && a[j] != b[i]){
            s.insert(a[j]);
            j++;
            step++;
        }
        s.insert(b[i]);
        step++;
        j++;
        ans.push_back(step);
    }

    rep(i, n-1){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;

    return 0;
}
