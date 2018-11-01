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

    cout << 1 << " " << 0 << endl;

    string base;
    cin >> base;

    int lo = 0;
    int hi = 1e9 - 1;
    rep(i, n - 1){
        int mid = (lo + hi) / 2;
        cout << 1 << " " << mid << endl;

        string s;
        cin >> s;

        if(s == base){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout << 0 << " " << lo << " " << 2 << " " << lo + 1 << endl;

    return 0;
}
