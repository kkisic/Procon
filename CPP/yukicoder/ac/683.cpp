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

bool judge(int a, int b){
    if(a > b){
        swap(a, b);
    }
    if(a == 0){
        return true;
    }
    if(a % 2 == 1 && b % 2 == 1){
        return false;
    }

    bool res = false;
    if(a % 2 == 0 && b > 0){
        res |= judge(a / 2, b - 1);
    }
    if(b % 2 == 0 && a > 0){
        res |= judge(a - 1, b / 2);
    }

    return res;
}

signed main(){
    int a, b;
    cin >> a >> b;

    cout << (judge(a, b) ? "Yes" : "No") << endl;

    return 0;
}
