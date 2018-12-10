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

    string s;
    cin >> s;

    vector<int> len;
    int cnt = 0;
    bool ng = true;
    rep(i, SZ(s)){
        if(s[i] == 'a'){
            cnt++;
            ng = false;
        }
        if(s[i] == 'b'){
            len.push_back(cnt);
            cnt = 0;
        }
    }
    len.push_back(cnt);

    if(ng){
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    rep(i, SZ(len)){
        ans *= (len[i] + 1);
        ans %= MOD;
    }
    ans = (ans + MOD - 1) % MOD;

    cout << ans << endl;

    return 0;
}
