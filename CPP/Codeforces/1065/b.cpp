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

    int maxi = 0;
    for(int i = 1; i <= 100000; i++){
        int e = i * (i - 1) / 2;
        if(e < m){
            continue;
        }
        maxi = max(0LL, n - i);
        break;
    }
    if(m == 0){
        maxi = n;
    }

    int mini = max(0LL, n - m * 2);
    cout << mini << " " << maxi << endl;

    return 0;
}
