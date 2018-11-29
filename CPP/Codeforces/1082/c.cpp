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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> s(m+1, vector<int>());
    rep(i, n){
        int x, y;
        cin >> x >> y;

        s[x].push_back(y);
    }

    int len = 0;
    rep(i, m){
        len = max(len, SZ(s[i+1]));
        sort(ALL(s[i+1]), greater<int>());

        rep(j, SZ(s[i+1]) - 1){
            s[i+1][j+1] += s[i+1][j];
        }
    }

    vector<vector<int>> t(len, vector<int>());
    rep(i, m){
        rep(j, SZ(s[i+1])){
            t[j].push_back(s[i+1][j]);
        }
    }
    int ans = 0;
    rep(i, len){
        sort(ALL(t[i]), greater<int>());
        int sum = 0;
        rep(j, SZ(t[i])){
            sum += t[i][j];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}
