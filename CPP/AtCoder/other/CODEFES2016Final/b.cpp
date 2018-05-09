#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<double> l(3);
    l[0] = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    l[1] = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    l[2] = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    sort(l.begin(), l.end());

    double s = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    s = abs(s) / 2;
    double r = s * 2 / (l[0] + l[1] + l[2]);
    double ans = l[2] / (2 + l[2] / r);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
