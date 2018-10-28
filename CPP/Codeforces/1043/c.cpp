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
    string s;
    cin >> s;

    int n = s.length();

    string t = s;
    sort(t.begin(), t.end());

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == t[i]){
            continue;
        }

        ans[i] = 1;
        reverse(t.begin(), t.begin() + i + 1);
    }

    rep(i, n-1){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;

    return 0;
}
