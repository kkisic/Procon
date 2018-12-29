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
const int MOD = 998244353;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string a;
    cin >> n >> a;

    int head, tail;
    head = tail = 0;

    rep(i, n){
        if(a[i] != a[0]){
            break;
        }
        head++;
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] != a[n-1]){
            break;
        }
        tail++;
    }

    if(a[0] != a[n-1]){
        cout << head + tail + 1 << endl;
        return 0;
    }

    cout << (head + 1) * (tail + 1) % MOD << endl;

    return 0;
}
