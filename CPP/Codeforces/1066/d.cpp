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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int lo = -1;
    int hi = n-1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;

        int i = mid;
        int box = 0;
        while(i < n){
            int sum = 0;
            while(i < n && sum + a[i] <= k){
                sum += a[i++];
            }
            box++;
        }

        if(box <= m){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout << n - hi << endl;

    return 0;
}
