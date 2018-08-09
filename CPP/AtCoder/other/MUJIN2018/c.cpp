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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n, m;

int solve(const vector<vector<int>>& c, const vector<vector<int>>& r, int i, int j){
    int lo, hi;

    lo = 0;
    hi = r[i].size();
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(r[i][mid] < j){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    int right = r[i][lo];

    lo = -1;
    hi = r[i].size()-1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(r[i][mid] > j){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    int left = r[i][hi];

    lo = 0;
    hi = c[j].size();
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(c[j][mid] < i){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    int top = c[j][lo];

    lo = -1;
    hi = c[j].size()-1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(c[j][mid] > i){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    int bottom = c[j][hi];

    right = j - right - 1;
    left = left - j - 1;
    top = i - top - 1;
    bottom = bottom - i - 1;

    int ans = right * top + top * left + left * bottom + bottom * right;

    return ans;
}

signed main(){
    cin >> n >> m;

    vector<vector<bool>> s(n, vector<bool>(m, false));
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if(c == '#'){
                s[i][j] = true;
            }
        }
    }

    vector<vector<int>> c(m+2, vector<int>()); //縦
    vector<vector<int>> r(n+2, vector<int>()); //横
    rep(i, m+2){
        c[i].push_back(0);
    }
    rep(i, n+2){
        r[i].push_back(0);
    }
    rep(i, n){
        rep(j, m){
            if(s[i][j]){
                c[j+1].push_back(i+1);
                r[i+1].push_back(j+1);
            }
        }
    }
    rep(i, m+2){
        c[i].push_back(n+1);
    }
    rep(i, n+2){
        r[i].push_back(m+1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1][j-1]){
                continue;
            }
            ans += solve(c, r, i, j);
        }
    }

    cout << ans << endl;

    return 0;
}
