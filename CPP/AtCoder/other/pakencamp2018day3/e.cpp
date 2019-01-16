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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    rep(i, q){
        int a, b, x;
        cin >> a >> b >> x;
        int g = gcd(a, b);
        a /= g;
        b /= g;

        if(x % g != 0){
            cout << 0 << endl;
            continue;
        }
        x /= g;

        vector<int> sum = {a, b};
        int j = 0;
        while(sum.back() < 1e17){
            sum.push_back(sum[j] + sum[j+1]);
            j++;
        }
        int n = SZ(sum);

        int ans = 0;
        int m = x;
        int end = (a >= b ? 1 : 0);
        for(int j = n - 1; j >= end; j--){
            if(sum[j] <= m){
                m -= sum[j];
            }
        }
        if(m == 0){
            ans++;
        }

        if(a >= b){
            int m = x - a;
            for(int j = n - 1; j >= 2; j--){
                if(sum[j] <= m){
                    m -= sum[j];
                }
            }
            if(m == 0){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
