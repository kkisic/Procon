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
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<int, int> m;
    set<int> st;
    rep(i, n){
        int open = 0;
        rep(j, SZ(s[i])){
            if(s[i][j] == '('){
                open++;
            }else{
                open--;
            }
        }

        bool ok = true;
        int c = 0;
        if(open >= 0){
            rep(j, SZ(s[i])){
                if(s[i][j] == '('){
                    c++;
                }else{
                    c--;
                }
                if(c < 0){
                    ok = false;
                    break;
                }
            }
        }else{
            for(int j = SZ(s[i]) - 1; j >= 0; j--){
                if(s[i][j] == '('){
                    c--;
                }else{
                    c++;
                }
                if(c < 0){
                    ok = false;
                    break;
                }
            }
        }

        if(not ok){
            continue;
        }

        if(m.find(open) == m.end()){
            m[open] = 0;
            st.insert(abs(open));
        }
        m[open]++;
    }

    int ans = 0;
    for(int x : st){
        if(x == 0){
            ans += m[x] / 2;
            continue;
        }
        ans += min(m[x], m[-x]);
    }
    cout << ans << endl;

    return 0;
}
