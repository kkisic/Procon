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

    string s;
    cin >> s;
    int n = s.length();

    string t = "keyence";

    int l, r;
    l = r = 0;
    rep(i, 7){
        if(s[i] != t[i]){
            break;
        }
        l = i + 1;
    }
    for(int i = 1; i <= 7; i++){
        if(s[n-i] != t[7-i]){
            break;
        }
        r = i;
    }

    if(l + r >= 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
