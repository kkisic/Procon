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

    rep(i, (int)s.length()){
        if(s[i] == 'I' || s[i] == 'l'){
            s[i] = '1';
        }
        if(s[i] == 'O' || s[i] == 'o'){
            s[i] = '0';
        }
    }
    cout << s << endl;

    return 0;
}
