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

    vector<int> p(n);
    rep(i, n) cin >> p[i];
    p.push_back(0);

    vector<int> sum;
    rep(i, n+1){
        for(int j = i; j <= n; j++){
            sum.push_back(p[i] + p[j]);
        }
    }
    sort(sum.begin(), sum.end());

    int ans = 0;
    rep(i, (int)sum.size()){
        if(sum[i] > m){
            continue;
        }
        int lo = 0;
        int hi = sum.size();

        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(sum[mid] <= m - sum[i]){
                lo = mid;
            }else{
                hi = mid;
            }
        }

        if(sum[lo] + sum[i] > ans){
            ans = sum[lo] + sum[i];
        }
    }
    cout << ans << endl;

    return 0;
}
