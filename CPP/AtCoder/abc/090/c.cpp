#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 1 || m == 1){
        cout << n*m - 2 << endl;
        return 0;
    }
    if(n == 2 || m == 2){
        cout << 0 << endl;
        return 0;
    }
    cout << n * m - (n + m) * 2 + 4 << endl;

    return 0;
}
