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
    int n, d;
    cin >> n >> d;

    vector<int> x(n);
    rep(i, n) cin >> x[i];

    vector<int> right(n), left(n);
    rep(i, n){
        int l = i;
        int r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(x[m] - x[i] <= d){
                l = m;
            }else{
                r = m;
            }
        }
        right[i] = l;

        l = -1;
        r = i;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(x[i] - x[m] <= d){
                r = m;
            }else{
                l = m;
            }
        }
        left[i] = r;
    }

    int a = 0;
    rep(i, n){
        if(right[i] - i < 2){
            continue;
        }
        a += (right[i] - i) * (right[i] - i - 1) / 2;
    }

    int b = 0;
    rep(i, n){
        if(i - left[i] < 1 || right[i] - i < 1){
            continue;
        }
        b += (i - left[i]) * (right[i] - i);
    }
    cout << b - a << endl;
    return 0;
}
