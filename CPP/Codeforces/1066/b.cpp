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
    int n, r;
    cin >> n >> r;

    vector<bool> a(n, false);
    rep(i, n){
        int x;
        cin >> x;
        if(x == 1){
            a[i] = true;
        }
    }

    int ans = 0;
    int i = 0;
    while(i < n){
        int isR = -1;
        for(int j = max(0LL, i - r + 1); j < i + r && j < n; j++){
            if(a[j]){
                isR = j;
            }
        }

        if(isR == -1){
            cout << -1 << endl;
            return 0;
        }
        ans++;
        i = isR + r;
    }
    cout << ans << endl;

    return 0;
}
