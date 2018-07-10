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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i, n){
        rep(j, m-3){
            if(s[i][j] == 'L' && s[i][j+1] == 'O' && s[i][j+2] == 'V' && s[i][j+3] == 'E'){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
