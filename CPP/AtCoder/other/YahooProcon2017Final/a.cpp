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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int levenshtein(string s, string t){
    int lenS = s.length();
    int lenT = t.length();
    vector<vector<int>> dp(lenS+1, vector<int>(lenT));

    rep(i, lenS+1){
        dp[i][0] = i;
    }
    rep(i, lenT){
        dp[0][i] = i;
    }

    rep(i, lenS){
        rep(j, lenT*2){
            dp[i+1][(j+1)%5] = min(dp[i+1][j%5]+1, dp[i][(j+1)%5]+1);
            int c = s[i] == t[j%5] ? 0 : 1;
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j%5] + c);
        }
    }
    return dp[lenS][0];
}

signed main(){
    string s;
    cin >> s;
    string t = "yahoo";

    cout << levenshtein(s, t) << endl;
    return 0;
}
