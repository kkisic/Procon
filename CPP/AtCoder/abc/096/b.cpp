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
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if(a > b && a > c){
        cout << b + c + a * pow(2, k) << endl;
        return 0;
    }

    if(b > a && b > c){
        cout << a + c + b * pow(2, k) << endl;
        return 0;
    }
    cout << a + b + c * pow(2, k) << endl;
    return 0;
}
