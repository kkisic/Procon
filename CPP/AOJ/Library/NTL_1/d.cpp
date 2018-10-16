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

    //prime factors
    vector<int> pf;
    int m = n;
    for(int i = 2; i <= sqrt(n); i++){
        if(m % i == 0){
            pf.push_back(i);
            while(m % i == 0) m /= i;
        }
    }
    if(m != 1){
        pf.push_back(m);
    }

    int num = pf.size();
    int ans = 0;
    for(int s = 1; s < (1 << num); s++){
        int cnt = __builtin_popcount(s);

        int x = 1;
        rep(i, num){
            if((s >> i) % 2 == 1){
                x *= pf[i];
            }
        }

        if(cnt % 2 == 1){
            ans += n / x;
        }else{
            ans -= n / x;
        }
    }

    cout << n - ans << endl;

    return 0;
}
