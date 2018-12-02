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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> m;
    rep(i, n){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = 0;
        }
        m[a[i]]++;
    }

    vector<int> num;
    for(P p : m){
        num.push_back(p.second);
    }
    sort(ALL(num), greater<int>());

    int ans = 0;
    int maxi = *max_element(ALL(num));
    for(int i = maxi; i >= 1; i--){
        int x = i;
        int tmp = 0;
        rep(j, SZ(num)){
            if(num[j] < x){
                break;
            }
            tmp += x;
            if(x % 2 == 1){
                break;
            }
            x /= 2;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
