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
    while(true){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0){
            break;
        }

        vector<int> a(n);
        rep(i, n) cin >> a[i];

        int ans = -1;
        rep(i, n){
            rep(j, n){
                if(i == j){
                    continue;
                }

                int tmp = a[i] + a[j];
                if(tmp > ans && tmp <= m){
                    ans = tmp;
                }
            }
        }
        if(ans == -1){
            cout << "NONE" << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}
