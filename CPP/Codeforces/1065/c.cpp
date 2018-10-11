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
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int maxi = 0;
    int mini = INF;
    rep(i, n){
        if(maxi < h[i]){
            maxi = h[i];
        }
        if(mini > h[i]){
            mini = h[i];
        }
    }

    vector<int> cnt(maxi + 1);
    rep(i, n){
        cnt[h[i]]++;
    }

    vector<int> s(maxi);
    s[maxi-1] = cnt[maxi];
    for(int i = maxi-1; i > 0; i--){
        s[i-1] = s[i] + cnt[i];
    }

    int ans = 0;
    for(int i = maxi - 1; i >= mini; i--){
        int sum = 0;
        int j = i;
        while(sum + s[j] <= k && j >= mini){
            sum += s[j];
            j--;
        }
        ans++;
        i = j + 1;
    }

    cout << ans << endl;

    return 0;
}
