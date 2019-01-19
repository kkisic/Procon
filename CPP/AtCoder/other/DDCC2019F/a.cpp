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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<P> r; // [i, j)
    double ans = -1;
    rep(i, n){
        if(s[i] == '-'){
            ans += 1;
            continue;
        }
        if(i == 0 || s[i-1] == '-'){
            r.emplace_back(i, i+1);
            continue;
        }
        if(s[i-1] == '>'){
            r.back().second++;
        }
    }

    int connect = -1;
    int maxi = 0;
    rep(i, SZ(r)){
        int tmp = r[i].second - r[i].first + 1;
        if(maxi < tmp){
            maxi = tmp;
            connect = i;
        }
    }

    rep(i, SZ(r)){
        int k = 0;
        for(int j = r[i].first; j < r[i].second; j++){
            ans += 1.0 / (k + 2.0);
            k++;
        }
        if(i == connect){
            ans += 1.0 / (k + 2.0);
        }
    }

    if(r.empty()){
        ans += 0.5;
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
