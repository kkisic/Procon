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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    vector<int> t;
    rep(i, n){
        for(int j = i; j < n; j++){
            t.push_back(s[j+1] - s[i]);
        }
    }

    sort(ALL(t), greater<int>());
    int head = 0;
    int last = SZ(t) - 1;
    int ans = 0;
    for(int i = 40; i >= 0; i--){
        int cnt = 0;
        int tmpH, tmpL;
        int sum = ans ^ (1LL << i);
        for(int j = head; j <= last; j++){
            if((t[j] & sum) == sum){
                if(cnt == 0){
                    tmpH = j;
                }
                cnt++;
                if(cnt >= k){
                    tmpL = j;
                }
            }
        }
        if(cnt >= k){
            ans += (1LL << i);
            head = tmpH;
            last = tmpL;
        }
    }
    cout << ans << endl;

    return 0;
}
