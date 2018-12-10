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

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v));

    int sum = 0;
    rep(i, n){
        sum += v[i];
    }

    if(sum < s){
        cout << -1 << endl;
        return 0;
    }

    int mini = v[0];
    int tmp = 0;
    rep(i, n){
        tmp += (v[i] - mini);
    }
    int diff = s - tmp;

    if(diff <= 0){
        cout << mini << endl;
        return 0;
    }

    cout << mini - (diff + n - 1) / n << endl;

    return 0;
}
