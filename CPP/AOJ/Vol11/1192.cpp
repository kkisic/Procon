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

void solve(int x, int y, int s){
    int ans = 0;
    for(int i = 1; i < s; i++){
        int ni = i * (100 + x) / 100;
        for(int j = 1; j <= s - ni; j++){
            int nj = j * (100 + x) / 100;

            if(ni + nj == s){
                int mi = i * (100 + y) / 100;
                int mj = j * (100 + y) / 100;

                if(mi + mj > ans){
                    ans = mi + mj;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    while(true){
        int x, y, s;
        cin >> x >> y >> s;

        if(x == 0 && y == 0 && s == 0){
            break;
        }

        solve(x, y, s);
    }

    return 0;
}
