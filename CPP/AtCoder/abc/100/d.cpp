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
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n), z(n);
    rep(i, n){
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<int> a = {1, -1};
    int ans = 0;
    rep(i, 2){
        rep(j, 2){
            rep(k, 2){
                vector<int> b(n);
                rep(l, n){
                    b[l] = x[l] * a[i] + y[l] * a[j] + z[l] * a[k];
                }
                sort(b.begin(), b.end());
                int tmp = 0;
                rep(i, m){
                    tmp += b[n-1-i];
                }
                if(tmp > ans){
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
