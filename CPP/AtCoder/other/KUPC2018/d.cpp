#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    cout << "? " << 2 << endl;
    string s;
    cin >> s;
    int x = s == "even" ? 0 : 1;

    int lo = 0;
    int hi = 500000000;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;

        if((mid * 2 < hi)){
            mid++;
        }

        cout << "? " << mid * 2 + 1 << endl;
        cin >> s;
        int y = s == "even" ? 0 : 1;
        if(y == x){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    if(x == 0){
        cout << "! " << hi * 2 << endl;
    }else{
        cout << "! " << hi * 2 - 1 << endl;
    }

    return 0;
}
