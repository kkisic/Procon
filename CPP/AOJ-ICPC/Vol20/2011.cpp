#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

void solve(int n){
    vector<int> day(31);
    rep(i, n){
        int d;
        cin >> d;

        rep(j, d){
            int x;
            cin >> x;
            day[x] |= (1LL << i);
        }
    }

    vector<int> map(n);
    rep(i, n){
        map[i] = 1LL << i;
    }
    for(int i = 1; i <= 30; i++){
        int tmp = 0;
        rep(j, n){
            if((day[i] >> j) % 2 == 1LL){
                tmp |= map[j];
            }
        }
        rep(j, n){
            if((day[i] >> j) % 2 == 1LL){
                map[j] |= tmp;
            }
            if(map[j] == (1LL << n) - 1LL){
                cout << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}

signed main(){
    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        solve(n);
    }

    return 0;
}
