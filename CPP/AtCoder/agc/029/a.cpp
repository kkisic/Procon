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

    int w, b;
    w = b = 0;
    for(char c : s){
        if(c == 'B'){
            b++;
        }else{
            w++;
        }
    }

    int ans = 0;
    int pos = 0;
    rep(i, SZ(s)){
        if(s[i] == 'B'){
            continue;
        }
        ans += i - pos;
        pos++;
    }
    cout << ans << endl;

    return 0;
}
