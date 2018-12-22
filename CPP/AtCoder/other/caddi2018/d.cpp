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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(ALL(a));

    int ans = 0;
    int m = n;
    int pre = 0;
    rep(i, n){
        int tmp = a[i] - pre;
        if(tmp % 2){
            ans ^= m;
        }
        pre = a[i];
        m--;
    }

    if(ans == 0){
        cout << "second" << endl;
    }else{
        cout << "first" << endl;
    }

    return 0;
}
