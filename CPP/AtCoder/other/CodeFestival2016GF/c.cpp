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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;
    rep(i, n) sum ^= a[i];

    vector<bool> k(31, false);
    rep(i, n){
        int x = a[i] ^ (a[i]-1);
        rep(j, 31){
            if(x == (1 << j) - 1){
                k[j] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 30; i >= 0; i--){
        if((sum >> i) == 0){
            continue;
        }

        if(k[i+1]){
            sum ^= (1 << (i+1)) - 1;
            ans++;
        }
    }

    if(sum == 0){
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
