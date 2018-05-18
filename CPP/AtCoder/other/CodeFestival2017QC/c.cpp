#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
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

    string t = s;
    reverse(t.begin(), t.end());
    int is = 0;
    int it = 0;
    int ans = 0;
    while(is < (int)s.length() || it < (int)t.length()){
        if(s[is] == t[it]){
            is++;
            it++;
            continue;
        }
        if(s[is] == 'x'){
            is++;
            ans++;
            continue;
        }
        if(t[it] == 'x'){
            it++;
            ans++;
            continue;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << ans / 2 << endl;

    return 0;
}
