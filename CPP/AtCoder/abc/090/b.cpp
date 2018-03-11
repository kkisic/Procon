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
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = a; i <= b; i++){
        if(i % 10 == i / 10000 && i % 100 / 10 == i / 1000 % 10){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
