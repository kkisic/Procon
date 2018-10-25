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

int n, m, k;

bool check(vector<int>& a, vector<int>& b, int x){
    int cnt = 0;
    for(int i = 0, j = 0; i < n && j < m; i++){
        while(j < m && b[j] < a[i] - x){
            j++;
        }
        if(abs(b[j] - a[i]) <= x){
            cnt++;
            j++;
        }
    }

    return cnt >= k;
}

signed main(){
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = -1;
    int hi = 1e9;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(check(a, b, mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout << hi << endl;

    return 0;
}
