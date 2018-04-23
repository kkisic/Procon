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
    int n, a, b;
    cin >> n >> a >> b;

    if(a > b){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1 && a != b){
        cout << 0 << endl;
        return 0;
    }
    int min = a;
    int max = b;
    if(n > 1){
        min += b + (n - 2) * a;
        max += a + (n - 2) * b;
    }

    cout << max - min + 1 << endl;

    return 0;
}

