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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    if(n == 1){
        cout << p << endl;
        return 0;
    }

    vector<int> vp = prime(1000000);
    vector<int> a(SZ(vp));

    int m = p;
    rep(i, SZ(vp)){
        if(m % vp[i] == 0){
            while(m % vp[i] == 0){
                m /= vp[i];
                a[i]++;
            }
        }
    }

    int ans = 1;
    rep(i, SZ(vp)){
        if(a[i] >= n){
            while(a[i] >= n){
                ans *= vp[i];
                a[i] -= n;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
