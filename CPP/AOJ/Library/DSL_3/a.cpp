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
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;
    int len = INF;
    int j = 0;
    rep(i, n){
        while(sum < s && j < n){
            sum += a[j++];
        }
        if(j - i < len && sum >= s){
            len = j - i;
        }
        sum -= a[i];
    }
    cout << (len == INF ? 0 : len) << endl;

    return 0;
}
