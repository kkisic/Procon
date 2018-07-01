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
    vector<P> a;
    rep(i, m){
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    sort(a.begin(), a.end());

    vector<int> min(n+1), max(n+1);
    rep(i, n){
        min[i+1] = max[i+1] = i+1;
    }

    rep(i, m){
        int y = a[i].second;
        min[y+1] = min[y];
        max[y] = max[y+1];
    }

    for(int i = 1; i < n; i++){
        cout << max[i] - min[i] + 1 << " ";
    }
    cout << max[n] - min[n] + 1 << endl;

    return 0;
}
