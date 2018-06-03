#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
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

    int ans = INF;
    for(int i = 1; i < n; i++){
        int x = i;
        int m = n - i;

        int tmp = 0;
        while(x > 0){
            tmp += x % 10;
            x /= 10;
        }

        while(m > 0){
            tmp += m % 10;
            m /= 10;
        }
        if(tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
