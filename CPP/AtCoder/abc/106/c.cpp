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
    int k;
    cin >> s >> k;

    int one = 0;
    char next;
    rep(i, (int)s.length()){
        if(s[i] != '1'){
            next = s[i];
            break;
        }
        one++;
    }

    if(k <= one){
        cout << 1 << endl;
    }else{
        cout << next << endl;
    }

    return 0;
}
