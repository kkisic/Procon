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

int solve(const vector<vector<int>>& b, const vector<int>& s, const vector<int>& p, int n, int x){
    int res = 0;
    rep(i, 5){
        if(x < b[n][i]){
            break;
        }
        x -= b[n][i];
        if(i % 2 == 1){
            res += p[n-1];
        }
        if(i == 2){
            res += 1;
        }
    }

    if(x != 0){
        res += solve(b, s, p, n-1, x);
    }

    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<vector<int>> b(51, vector<int>(5));
    vector<int> s(51);
    vector<int> p(51);
    b[0][0] = 1;
    s[0] = 1;
    p[0] = 1;

    rep(i, 50){
        b[i+1][0] = 1;
        b[i+1][1] = s[i];
        b[i+1][2] = 1;
        b[i+1][3] = s[i];
        b[i+1][4] = 1;

        rep(j, 5){
            s[i+1] += b[i+1][j];
        }
        p[i+1] = 1 + p[i] * 2;
    }

    cout << solve(b, s, p, n, x) << endl;

    return 0;
}
