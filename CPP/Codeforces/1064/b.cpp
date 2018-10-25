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
    int a;
    cin >> a;

    rep(i, a){
        int t;
        cin >> t;

        int cnt = 0;
        while(t != 0){
            if(t % 2 == 1){
                cnt++;
            }
            t /= 2;
        }

        cout << (int)pow(2, cnt) << endl;
    }

    return 0;
}
