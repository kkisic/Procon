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

bool compare(P a, P b){
    return a.first - a.second < b.first - b.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<P> x(n);
    rep(i, n) x[i] = {a[i], b[i]};
    sort(ALL(x), compare);

    int sum = 0;
    int s = -1;
    rep(i, n){
        if(x[i].first >= x[i].second){
            break;
        }
        sum += x[i].second - x[i].first;
        s = i;
    }

    int t = -1;
    for(int i = n - 1; i >= 0; i--){
        if(x[i].first <= x[i].second){
            break;
        }
        if(sum <= 0){
            break;
        }
        sum -= x[i].first - x[i].second;
        t = i;
    }

    if(sum > 0){
        cout << -1 << endl;
        return 0;
    }

    if(s == -1 || t == -1){
        cout << 0 << endl;
    }else{
        cout << s + 1 + n - t << endl;
    }

    return 0;
}
