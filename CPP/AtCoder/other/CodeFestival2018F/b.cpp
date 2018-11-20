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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

double f(int n){
    static vector<double> x(1, 0.0);
    if(n == 0){
        return 0.0;
    }

    if(n <= SZ(x)){
        return x[n-1];
    }

    for(int i = SZ(x); i < n; i++){
        x.push_back(x[i-1] + log10(i+1));
    }
    return x[n-1];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    double ans = -f(n);
    rep(i, m){
        int r;
        cin >> r;
        ans += f(r);
    }
    ans += log10(m) * (double)n;

    cout << ceil(ans) << endl;

    return 0;
}
