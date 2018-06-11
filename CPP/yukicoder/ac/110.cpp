#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int nw;
    cin >> nw;
    vector<int> w(nw);
    rep(i, nw) cin >> w[i];
    int nb;
    cin >> nb;
    vector<int> b(nb);
    rep(i, nb) cin >> b[i];
    sort(w.begin(), w.end());
    sort(b.begin(), b.end());

    vector<vector<int>> dp(2, vector<int>(21));
    int wi = 0;
    int bi = 0;
    if(w[wi] < b[bi]){
        dp[0][w[wi++]] = 1;
    }else if(w[wi] > b[bi]){
        dp[1][b[bi++]] = 1;
    }else{
        dp[0][w[wi++]] = 1;
        dp[1][b[bi++]] = 1;
    }
    while(wi < nw || bi < nb){
        if((wi < nw && bi < nb && w[wi] < b[bi]) || bi >= nb){
            for(int i = 0; b[i] < w[wi]; i++){
                dp[0][w[wi]] = max(dp[0][w[wi]], dp[1][b[i]] + 1);
            }
            wi++;
            continue;
        }

        for(int i = 0; w[i] < b[bi]; i++){
            dp[1][b[bi]] = max(dp[1][b[bi]], dp[0][w[i]] + 1);
        }
        bi++;
    }

    int ans = 0;
    rep(i, 2){
        rep(j, 21){
            if(dp[i][j] > ans){
                ans = dp[i][j];
            }
        }
    }
    cout<< ans << endl;
    return 0;
}
