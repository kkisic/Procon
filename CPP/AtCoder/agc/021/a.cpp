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
    int n;
    cin >> n;

    int x = n;
    int ans1 = 0;
    int head;
    int c = 0;
    while(x != 0){
        ans1 += x % 10;
        if(x < 10){
            head = x;
        }
        c++;
        x /= 10;
    }
    int tmp = head + 9 * (c-1) - 1;
    if(tmp > ans1){
        ans1 = tmp;
    }
    cout << ans1 << endl;

    return 0;
}
