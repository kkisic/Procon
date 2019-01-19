#include <cmath>
#include <cstdio>
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

    string s = "";
    char c;
    while(scanf("%c", &c) != EOF){
        if(c == '\n'){
            continue;
        }
        s.push_back(c);
    }
    vector<string> ans;
    ans.push_back("");
    rep(i, SZ(s)){
        if(s[i] != ' '){
            ans.back().push_back(s[i]);
            continue;
        }
        if(ans.back() != ""){
            ans.push_back("");
        }
    }

    rep(i, SZ(ans) - 1){
        cout << ans[i] << ",";
    }
    cout << ans[SZ(ans)-1] << endl;

    return 0;
}
