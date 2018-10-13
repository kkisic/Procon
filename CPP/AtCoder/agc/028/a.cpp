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

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }

    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

signed main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int g = gcd(n, m);
    int lcm = n * m / g;

    map<int, char> mm;
    rep(i, n){
        mm[lcm / n * i] = s[i];
    }

    bool ok = true;
    rep(i, m){
        if(mm.find(lcm / m * i) == mm.end()){
            continue;
        }

        if(mm[lcm / m * i] != t[i]){
            ok = false;
        }
    }

    if(ok){
        cout << lcm << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
