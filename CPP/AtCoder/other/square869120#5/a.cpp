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
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    for(int i = 1; i < n; i++){
        if(a[i-1] < a[i]){
            continue;
        }

        for(int j = i; j < n; j++){
            a[j] += t;
        }
    }
    cout << a[n-1] << endl;

    return 0;
}
