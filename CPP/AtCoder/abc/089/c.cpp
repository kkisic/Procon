#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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

    vector<string> s(n);
    vector<int> c(5);
    rep(i, n){
        cin >> s[i];
        if(s[i][0] == 'M'){
            c[0]++;
        }else if(s[i][0] == 'A'){
            c[1]++;
        }else if(s[i][0] == 'R'){
            c[2]++;
        }else if(s[i][0] == 'C'){
            c[3]++;
        }else if(s[i][0] == 'H'){
            c[4]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << 5)-1; i++){
        int x = 1;
        int p = 0;
        for(int j = 0; j < 5; j++){
            if((i >> j) & 1 == 1){
                x *= c[j];
                p ++;
            }
        }
        if(p == 3){
            ans += x;
        }
    }
    cout << ans << endl;

    return 0;
}
