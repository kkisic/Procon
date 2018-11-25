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

    int x, y;
    cin >> x >> y;


    int diff = abs(x - y);
    if(diff % 2 != 0){
        cout << "No" << endl;
        return 0;
    }
    diff /= 2;

    if(x > y){
        x -= diff * 3;
        y -= diff;
    }else{
        x -= diff;
        y -= diff * 3;
    }

    if(x < 0 || y < 0){
        cout << "No" << endl;
        return 0;
    }

    if(x % 4 == 0 && y % 4 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
