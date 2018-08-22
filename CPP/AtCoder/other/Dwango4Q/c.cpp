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

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    vector<int> ka(1), kb(1);
    int da, db;
    da = db = 0;
    int k = 0;
    rep(i, n){
        cin >> a[i];
        db += a[i];
        if(i > 0 && a[i-1] != a[i]){
            k++;
            ka.push_back(0);
        }
        ka[k]++;
    }
    k = 0;
    rep(i, m){
        cin >> b[i];
        da += b[i];
        if(i > 0 && b[i-1] != b[i]){
            k++;
            kb.push_back(0);
        }
        kb[k]++;
    }

    int player = max(n, m);
    int killSum = max(da, db);
    vector<vector<int>> death(player+1, vector<int>(killSum+1));
    death[1][0] = 1;
    for(int i = 1; i <= player; i++){
        for(int j = 0; j <= killSum; j++){
            if(i + j <= killSum){
                death[i][j+i] += death[i][j];
                death[i][j+i] %= MOD;
            }

            if(i + 1 <= player && j <= killSum){
                death[i+1][j] += death[i][j];
                death[i+1][j] %= MOD;
            }
        }
    }

    vector<vector<int>> dp1(ka.size()+1, vector<int>(killSum+1));
    vector<vector<int>> dp2(kb.size()+1, vector<int>(killSum+1));
    dp1[0][0] = dp2[0][0] = 1;
    rep(g, (int)ka.size()){
        rep(d, da+1){
            for(int i = 0; i <= da - d; i++){
                dp1[g+1][d+i] += death[ka[g]][i] * dp1[g][d] % MOD;
                dp1[g+1][d+i] %= MOD;
            }
        }
    }

    rep(g, (int)kb.size()){
        rep(d, db+1){
            for(int i = 0; i <= db - d; i++){
                dp2[g+1][d+i] += death[kb[g]][i] * dp2[g][d] % MOD;
                dp2[g+1][d+i] %= MOD;
            }
        }
    }

    cout << dp1[ka.size()][da] * dp2[kb.size()][db] % MOD << endl;


    return 0;
}
