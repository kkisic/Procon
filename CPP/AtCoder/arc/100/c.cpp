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
        x += abs(a[i] - (b + i+1));
    }
    return x;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] -= i+1;
    }
    sort(a.begin(), a.end());

    int b = a[n / 2];
    int s = 0;
    rep(i, n){
        s += abs(a[i] - b);
    }
    cout << s << endl;

    return 0;
}
