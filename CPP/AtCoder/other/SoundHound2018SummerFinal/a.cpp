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
    int c, d;
    cin >> c >> d;

    int begin = 140;
    int end = 170;

    int ans = 0;

    while(begin < d){
        if(end < c){
            begin *= 2;
            end *= 2;
            continue;
        }
        ans += min(d - 1, end - 1) - max(c, begin) + 1;
        begin *= 2;
        end *= 2;
    }
    cout << ans << endl;

    return 0;
}
