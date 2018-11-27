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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;

    bool t = true;
    rep(i, k){
        if(t){
            if(a % 2 != 0){
                a--;
            }
            b += a / 2;
            a /= 2;
            t = false;
        }else{
            if(b % 2 != 0){
                b--;
            }
            a += b / 2;
            b /= 2;
            t = true;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}
