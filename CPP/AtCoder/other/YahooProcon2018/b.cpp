#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    int x, k;
    cin >> x >> k;

    int y = pow(10, k);
    if(x < y){
        cout << y << endl;
        return 0;
    }

    y *= x / y + 1;
    cout << y << endl;
    return 0;
}
