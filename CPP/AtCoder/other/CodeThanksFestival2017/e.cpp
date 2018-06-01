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
    int n;
    cin >> n;

    vector<int> ans(n);
    int i = 0;
    while(i < n){
        vector<int> q(n);

        rep(j, 5){
            if(i + j >= n){
                continue;
            }
            q[i+j] = pow(5, j);
        }

        cout << "?";
        rep(j, n){
            cout << " " << q[j];
        }
        cout << endl;
        int weight;
        cin >> weight;

        for(int j = 4; j >= 0; j--){
            if(i + j >= n){
                continue;
            }
            weight -= 8 * pow(5, j);
        }

        for(int j = 4; j >= 0; j--){
            if(i + j >= n){
                continue;
            }
            ans[i+j] = weight / (int)pow(5, j);
            weight %= (int)pow(5, j);
        }
        i += 5;
    }

    cout << "!";
    rep(i, n){
        if(ans[i] == 1 || ans[i] == 3){
            cout << " 1";
        }else{
            cout << " 0";
        }
    }
    cout << endl;

    return 0;
}
