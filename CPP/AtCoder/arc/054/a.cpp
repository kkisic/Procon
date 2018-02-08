#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;

    int dist = ((d + l) - s) % l;

    double ans1 = (double)dist / (double)(x + y);
    double ans2 = (double)(l - dist) / (double)(y - x);

    if(ans1 < ans2 || ans2 < 0){
        cout << fixed << setprecision(6) << ans1 << endl;
        return 0;
    }
    cout << fixed << setprecision(6) << ans2 << endl;
    return 0;
}
