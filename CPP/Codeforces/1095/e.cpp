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
    string s;
    cin >> s;

    int open = 0;
    rep(i, n){
        open += (s[i] == '(' ? 1 : -1);
    }

    if(abs(open) != 2){
        cout << 0 << endl;
        return 0;
    }

    if(open < 0){
        string t;
        for(int i = n - 1; i >= 0; i--){
            t.push_back(s[i] == '(' ? ')' : '(');
        }
        s = t;
    }

    vector<int> a(n + 1);
    rep(i, n){
        if(s[i] == '('){
            a[i+1] = a[i] + 1;
        }else{
            a[i+1] = a[i] - 1;
        }
        if(a[i+1] < 0){
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i+1] < 2){
            break;
        }
        if(s[i] == '('){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
