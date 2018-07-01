#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int solve(){
    char c;
    cin >> c;

    if(c != '['){
        int x = 0;
        while(c != ']'){
            x *= 10;
            x += c - '0';
            cin >> c;
        }
        return (x / 2) + 1;
    }

    vector<int> a;
    while(c != ']'){
        a.push_back(solve());
        cin >> c;
    }
    sort(a.begin(), a.end());
    int n = ((int)a.size()) / 2 + 1;

    int x = 0;
    rep(i, n){
        x += a[i];
    }
    return x;
}

signed main(){
    int n;
    cin >> n;

    rep(i, n){
        char c;
        cin >> c;

        int ans = solve();
        cout << ans << endl;
    }

    return 0;
}
