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

signed main(){
    string s, t;
    cin >> s >> t;

    vector<int> a(200), b(200);
    rep(i, (int)s.length()){
        a[s[i]]++;
        b[t[i]]++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    rep(i, 200){
        if(a[i] != b[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
