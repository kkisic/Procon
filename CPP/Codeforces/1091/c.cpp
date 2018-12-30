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

    set<int> ans;
    for(int i = 1; i * i <= n; i++){
        if(n % i != 0){
            continue;
        }

        int sum = n / i;
        sum += (n / i) * (n / i - 1) / 2 * i;
        ans.insert(sum);

        int m = n / i;
        sum = n / m;
        sum += (n / m) * (n / m - 1) / 2 * m;
        ans.insert(sum);
    }

    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
