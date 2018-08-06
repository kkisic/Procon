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

int d, g;

int solve(vector<int> p, const vector<int>& c, int s){
    int ans = 0;
    int point = 0;

    rep(i, d){
        if((s >> i) % 2 == 0){
            continue;
        }
        ans += p[i];
        point += (i + 1) * 100 * p[i] + c[i];
        p[i] = 0;
    }

    while(point < g){
        for(int i = d - 1; i >= 0; i--){
            if(p[i] == 0){
                continue;
            }

            ans++;
            p[i]--;
            point += (i + 1) * 100;
            if(p[i] == 0){
                point += c[i];
            }
            break;
        }
    }

    return ans;
}

signed main(){
    cin >> d >> g;

    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];

    vector<int> cmp(d);
    rep(i, d){
        cmp[i] = (i + 1) * 100 * p[i] + c[i];
    }

    int ans = INF;
    rep(s, (1 << d)){
        int tmp = solve(p, c, s);
        if(ans > tmp){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
