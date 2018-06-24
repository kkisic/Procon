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

void solve(int m, int n){
    vector<bool> s(8000000, false);
    int y = m;
    while(true){
        if(s[y]){
            y++;
            continue;
        }

        if(n == 0){
            cout << y << endl;
            return;
        }

        for(int i = y; i < (int)s.size(); i += y){
            s[i] = true;
        }
        n--;
    }
}

signed main(){
    while(true){
        int m, n;
        cin >> m >> n;

        if(m == 0 && n == 0){
            break;
        }

        solve(m, n);
    }

    return 0;
}
