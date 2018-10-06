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
    int n;
    cin >> n;

    vector<int> x(n), y(n), h(n);
    rep(i, n){
        cin >> x[i] >> y[i] >> h[i];
    }

    int a = x[0];
    int b = y[0];
    int c = h[0];
    rep(i, n){
        if(h[i] > 0){
            a = x[i];
            b = y[i];
            c = h[i];
        }
    }

    rep(i, 101){
        rep(j, 101){
            bool ok = true;
            int ch = c + abs(i - a) + abs(j - b);

            for(int k = 0; k < n; k++){
                int nh = max(ch - abs(i - x[k]) - abs(j - y[k]), 0LL);
                if(nh != h[k]){
                    ok = false;
                    break;
                }
            }

            if(ok){
                cout << i << " " << j << " " << ch << endl;
                return 0;
            }
        }
    }

    return 0;
}
