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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }

    int r = a % b;
    while(r > 0){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= 3500; i++){
        for(int j = 1; j <= 3500; j++){
            int x = n * i * j;
            int y = 4 * i * j - n * i - n * j;

            if(y <= 0){
                continue;
            }

            if(x % y == 0){
                cout << i << " " << j << " " << x / y << endl;
                return 0;
            }
        }
    }

    return 0;
}
