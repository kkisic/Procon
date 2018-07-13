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
    string n;
    cin >> n;

    int head = 0;
    rep(i, 3){
        head *= 10;
        head += n[i] - '0';
    }

    if(995 <= head && head <= 999){
        cout << "1.0*10^" << n.length() << endl;
        return 0;
    }

    int ans = head / 10;
    if(head % 10 >= 5){
        ans += 1;
    }

    cout << fixed << setprecision(1) << (double)ans / 10.0 << "*10^" << n.length() - 1 << endl;

    return 0;
}
