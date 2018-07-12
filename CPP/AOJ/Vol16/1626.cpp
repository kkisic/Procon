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

P noAns = make_pair(0, 0);

P solve(int x, int y){
    if(x % 2 == 0 && y % 2 == 1){
        if(x - y / 2 <= 0){
            return noAns;
        }
        return make_pair(x - y / 2, y);
    }

    if(x % 2 == 1 && y % 2 == 0){
        if(x / 2 < y){
            return noAns;
        }
        return make_pair(x / 2 - y + 1, y * 2);
    }

    if(x / 2 >= y){
        return make_pair(x / 2 - y + 1, y * 2);
    }

    if(x - y / 2 > 0){
        return make_pair(x - y / 2, y);
    }
    return noAns;
}

signed main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        int ans = 0;
        int m;
        for(int i = 1; i * i <= n; i++){
            if(n % i != 0){
                continue;
            }
            if(i % 2 == 0 && n / i % 2 == 0){
                continue;
            }
            int x = i;
            int y = n / i;

            P p = solve(x, y);
            if(ans < p.second){
                ans = p.second;
                m = p.first;
            }

            p = solve(y, x);
            if(ans < p.second){
                ans = p.second;
                m = p.first;
            }
        }
        cout << m << " " << ans << endl;
    }

    return 0;
}
