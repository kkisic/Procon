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
const int LEN = 100;

signed main(){
    int a, b;
    cin >> a >> b;
    int c = min(a, b); //false w.
    int d = max(a, b); //true b#

    vector<vector<bool>> ans(LEN, vector<bool>(LEN, false));

    int cnt = 0;
    int i, j;
    i = j = 0;
    for(i = 0; i < LEN; i += 4){
        bool f = false;
        for(j = 0; j < LEN; j += 4){
            if(cnt == c - 1){
                f = true;
                break;
            }
            ans[i][j] = true;
            ans[i][j+1] = true;
            ans[i][j+2] = true;
            ans[i+1][j] = true;
            ans[i+1][j+2] = true;
            ans[i+2][j] = true;
            ans[i+2][j+1] = true;
            ans[i+2][j+2] = true;
            cnt++;
        }
        if(f){
            i += 4;
            break;
        }
    }

    cnt = 0;
    for(; i < LEN; i += 4){
        bool f = false;
        for(j = 0; j < LEN; j += 4){
            if(cnt == d - c + 1){
                f = true;
                break;
            }
            ans[i][j] = true;
            cnt++;
        }
        if(f){
            break;
        }
    }

    if(a > b){
        for(i = 0; i < LEN; i++){
            for(j = 0; j < LEN; j++){
                ans[i][j] = not ans[i][j];
            }
        }
    }

    cout << 100 << " " << 100 << endl;
    for(i = 0; i < LEN; i++){
        for(j = 0; j < LEN; j++){
            if(ans[i][j]){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}
