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

int n;
int x, y;

bool check(vector<int>& xs, vector<int>& ys, int d){
    for(int i = 0; i <= n - d; i++){
        int xx = xs[i] - xs[i+d] + xs[n];
        int yy = ys[i] - ys[i+d] + ys[n];

        if(abs(xx - x) + abs(yy - y) <= d){
            return true;
        }
    }
    return false;
}

signed main(){
    string s;
    cin >> n >> s >> x >> y;

    if(n % 2 != (abs(x) + abs(y)) % 2){
        cout << -1 << endl;
        return 0;
    }

    vector<int> xs(n+1), ys(n+1);

    rep(i, n){
        if(s[i] == 'U'){
            xs[i+1] = xs[i];
            ys[i+1] = ys[i] + 1;
        }
        if(s[i] == 'R'){
            xs[i+1] = xs[i] + 1;
            ys[i+1] = ys[i];
        }
        if(s[i] == 'D'){
            xs[i+1] = xs[i];
            ys[i+1] = ys[i] - 1;
        }
        if(s[i] == 'L'){
            xs[i+1] = xs[i] - 1;
            ys[i+1] = ys[i];
        }
    }

    int lo = -1;
    int hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(check(xs, ys, mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    if(check(xs, ys, hi)){
        cout << hi << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
