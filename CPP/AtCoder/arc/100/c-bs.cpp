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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int f(const vector<int>& a, int b){
    int x = 0;
    rep(i, (int)a.size()){
        x += abs(a[i] - (b+i+1));
    }
    return x;
}

int binary_search(const vector<int>& a){
    // 関数f(下に凸)の極小値
    int lo = -1e9;
    int hi = 1e9;
    while(hi - lo > 1){
        int m = (lo + hi) / 2;
        if(f(a, m) >= f(a, m+1)){
            lo = m;
        }else{
            hi = m;
        }
    }
    return f(a, hi);
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    cout << binary_search(a) << endl;

    return 0;
}
