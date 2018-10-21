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
    int q;
    cin >> q;

    rep(i, q){
        int a, b, c;
        cin >> a >> b >> c;

        int s = a * 100 + b * 10 + c;
        if(s % 2 == 1){
            cout << "No" << endl;
            continue;
        }

        s /= 2;
        s -= min(s / 100, a) * 100;
        s -= min(s / 10, b) * 10;
        s -= min(s, c);

        cout << (s == 0 ? "Yes" : "No") << endl;
    }

    return 0;
}
