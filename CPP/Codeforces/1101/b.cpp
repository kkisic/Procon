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
    int n = s.length();

    int l, r;
    l = r = -1;
    rep(i, n){
        if(l == -1 && s[i] == '['){
            l = -2;
        }
        if(l != -1 && s[i] == ':'){
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(r == -1 && s[i] == ']'){
            r = -2;
        }
        if(r != -1 && s[i] == ':'){
            r = i;
            break;
        }
    }

    if(l >= r || l < 0 || r < 0){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = l; i < r; i++){
        if(s[i] == '|'){
            ans++;
        }
    }
    cout << 4 + ans << endl;

    return 0;
}
