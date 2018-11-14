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

    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << " " << 0 << endl;
        return 0;
    }

    vector<int> p = prime(100000);
    vector<int> x;

    int a = 1;
    rep(i, SZ(p)){
        if(n % p[i] == 0){
            int tmp = 0;
            while(n % p[i] == 0){
                tmp++;
                n /= p[i];
            }
            x.push_back(tmp);
            a *= p[i];
        }
    }

    if(n != 1){
        a *= n;
        x.push_back(1);
    }

    int ans = 0;
    rep(i, SZ(x)){
        int tmp = 1;
        int cnt = 0;
        while(tmp < x[i]){
            tmp *= 2;
            cnt++;
        }
        if(ans < cnt){
            ans = cnt;
        }
    }

    bool ok = true;
    int maxi = *max_element(x.begin(), x.end());
    int y = maxi;
    while(y % 2 == 0){
        y /= 2;
    }

    if(y != 1){
        ok = false;
    }

    sort(x.begin(), x.end());
    UNIQUE(x);
    if(SZ(x) > 1){
        ok = false;
    }

    if(not ok){
        ans++;
    }

    cout << a << " " << ans << endl;

    return 0;
}
