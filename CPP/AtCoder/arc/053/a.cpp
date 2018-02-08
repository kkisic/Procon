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
    int h, w;
    cin >> h >> w;

    int ans = (h-1)*w + (w-1)*h;
    cout << ans << endl;

    return 0;
}
