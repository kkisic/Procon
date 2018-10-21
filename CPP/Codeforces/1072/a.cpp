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

template <typename T>
void debugv(vector<T>& vec){
    for(T t : vec){
        cout << t << endl;
    }
    cout << endl;
}

signed main(){
    int h, w, k;
    cin >> h >> w >> k;

    int ans = 0;
    rep(i, k){
        ans += w * 2 + (h - 2) * 2;
        w -= 4;
        h -= 4;
    }
    cout << ans << endl;

    return 0;
}
