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

    rep(i, h){
        rep(j, w){
            string s;
            cin >> s;

            if("snuke" == s){
                cout << (char)('A'+j) << i+1 << endl;
            }
        }
    }

    return 0;
}
