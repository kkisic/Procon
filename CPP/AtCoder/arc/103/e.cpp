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

    if(s[0] == '0' || s[n-1] == '1'){
        cout << -1 << endl;
        return 0;
    }

    vector<bool> len(n, false);
    for(int i = 1; i <= n / 2; i++){
        if(s[i] != s[n-i-2]){
            cout << -1 << endl;
            return 0;
        }
        if(s[i] == '1'){
            len[i+1] = true;
        }
    }

    vector<P> ans;
    int parent = 2;
    ans.emplace_back(1, 2);
    int v = 3;
    for(int i = 2; i <= n / 2; i++){
        ans.emplace_back(parent, v);
        if(not len[i]){
            v++;
            continue;
        }
        parent = v;
        v++;
    }
    for(; v <= n; v++){
        ans.emplace_back(parent, v);
    }

    rep(i, n-1){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
