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

    int n;
    cin >> n;
    vector<string> s(2 * n - 2);
    rep(i, 2 * n - 2) cin >> s[i];

    vector<string> t;
    rep(i, 2 * n - 2){
        if(SZ(s[i]) == n - 1){
            t.push_back(s[i]);
        }
    }

    vector<string> ss;
    if(t[0].substr(0, n - 2) == t[1].substr(1)){
        string st = t[1];
        st.push_back(t[0][n-2]);
        ss.push_back(st);
    }
    if(t[1].substr(0, n - 2) == t[0].substr(1)){
        string st = t[0];
        st.push_back(t[1][n-2]);
        ss.push_back(st);
    }

    rep(i, SZ(ss)){
        vector<bool> pre(n-1, false), suf(n-1, false);
        vector<int> ans(2 * n - 2);
        bool isAns = true;

        rep(j, 2 * n - 2){
            if(ss[i].substr(0, SZ(s[j])) == s[j] && not pre[SZ(s[j])]){
                pre[SZ(s[j])] = true;
                ans[j] = 1;
                continue;
            }

            int diff = n - SZ(s[j]);
            if(ss[i].substr(diff) == s[j]){
                suf[SZ(s[j])] = true;
                ans[j] = -1;
                continue;
            }

            isAns = false;
            break;
        }

        if(isAns){
            rep(j, 2 * n - 2){
                cout << (ans[j] == 1 ? "P" : "S");
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}
