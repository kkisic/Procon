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

    int n;
    cin >> n;

    int h, w;
    h = w = 0;
    rep(i, n){
        char c;
        int x, y;
        cin >> c >> x >> y;

        if(x > y){
            swap(x, y);
        }

        if(c == '+'){
            h = max(h, x);
            w = max(w, y);
        }else{
            if(h <= x && w <= y){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
