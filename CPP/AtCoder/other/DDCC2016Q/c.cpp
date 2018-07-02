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
#include <utility>
#include <numeric>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> m;
    rep(i, n){
        int r = gcd(a[i], k);
        if(m.find(r) == m.end()){
            m.emplace(r, 0);
        }
        m[r]++;
    }

    vector<P> p;
    for(auto it = m.begin(); it != m.end(); it++){
        p.push_back(*it);
    }

    int ans = 0;
    rep(i, (int)p.size()){
        for(int j = i; j < (int)p.size(); j++){
            if(p[i].first * p[j].first % k != 0){
                continue;
            }
            if(i == j){
                ans += p[i].second * (p[j].second - 1) / 2;
                continue;
            }
            ans += p[i].second * p[j].second;
        }
    }
    cout << ans << endl;

    return 0;
}
