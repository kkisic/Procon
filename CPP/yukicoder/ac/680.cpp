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

int n;

bool judge(int s, int t){
    if(s == n){
        return true;
    }
    t *= 2;
    if(s + t > n){
        return false;
    }

    if(s == 0){
        return judge(s + t + 1, t + 1);
    }
    return judge(s + t, t) || judge(s + t + 1, t + 1);
}

signed main(){
    cin >> n;
    cout << (judge(0, 0) ? "YES" : "NO") << endl;

    return 0;
}
