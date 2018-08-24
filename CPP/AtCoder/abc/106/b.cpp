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
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        int k = 0;
        for(int x = 1; x * x <= i; x++){
            if(i % x != 0){
                continue;
            }
            k += 2;

            if(x * x == i){
                k--;
            }
        }

        if(k == 8){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
