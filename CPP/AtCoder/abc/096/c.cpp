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
    int h, w;
    cin >> h >> w;

    vector<vector<bool>> s(h, vector<bool>(w, false));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == '#'){
                s[i][j] = true;
            }
        }
    }

    rep(i, h){
        rep(j, w){
            if(!s[i][j]){
                continue;
            }
            bool ok = false;
            if(i > 0 && s[i-1][j]){
                ok = true;
            }
            if(j > 0 && s[i][j-1]){
                ok = true;
            }
            if(i < h-1 && s[i+1][j]){
                ok = true;
            }
            if(j < w-1 && s[i][j+1]){
                ok = true;
            }
            if(!ok){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
