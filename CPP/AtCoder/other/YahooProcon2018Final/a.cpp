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

vector<int> getPrimeFactors(int x){
    vector<int> pf;
    int n = x;
    for(int i = 2; i <= sqrt(x); i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            pf.push_back(i);
        }
    }
    if(n != 1){
        pf.push_back(n);
    }
    return pf;
}

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> cnt(100001);
    rep(i, n){
        int a;
        cin >> a;

        vector<int> pf = getPrimeFactors(a);
        int num = pf.size();
        rep(s, (1 << num)){
            int x = 1;
            rep(j, num){
                if((s >> j) % 2 == 1){
                    x *= pf[j];
                }
            }
            cnt[x]++;
        }
    }

    cout << n << endl;
    for(int i = 2; i <= m; i++){
        vector<int> pf = getPrimeFactors(i);
        int num = pf.size();
        int ans = 0;
        for(int s = 1; s < (1 << num); s++){
            int count = __builtin_popcount(s);
            int x = 1;
            rep(j, num){
                if((s >> j) % 2 == 1){
                    x *= pf[j];
                }
            }
            if(count % 2 == 1){
                ans += cnt[x];
            }else{
                ans -= cnt[x];
            }
        }
        cout << n - ans << endl;
    }

    return 0;
}
