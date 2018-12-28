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

    int n, k;
    cin >> n >> k;

    vector<int> p(31);
    p[0] = 1;
    rep(i, 30){
        p[i+1] = p[i] * 2;
    }

    priority_queue<int> ans;
    int m = n;
    for(int i = 30; i >= 0; i--){
        int tmp = m / p[i];
        rep(j, tmp){
            ans.push(p[i]);
        }
        m %= p[i];
    }

    if(SZ(ans) > k){
        cout << "NO" << endl;
        return 0;
    }

    int cnt = k - SZ(ans);
    rep(i, cnt){
        if(ans.top() == 1){
            cout << "NO" << endl;
            return 0;
        }
        int x = ans.top();
        ans.pop();
        ans.push(x / 2);
        ans.push(x / 2);
    }

    cout << "YES" << endl;
    rep(i, k - 1){
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << ans.top() << endl;

    return 0;
}
