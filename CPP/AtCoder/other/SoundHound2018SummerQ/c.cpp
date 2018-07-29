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
    double n, m, d;
    cin >> n >> m >> d;

    int x = d == 0 ? n : (n-d)*2;

    cout << fixed << setprecision(6) << x / (n * n) * (m-1) << endl;

    return 0;
}
