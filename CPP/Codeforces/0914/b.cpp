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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> m;
    rep(i, n){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = 0;
        }
        m[a[i]]++;
    }

    for(P p : m){
        if(p.second % 2 == 1){
            cout << "Conan" << endl;
            return 0;
        }
    }
    cout << "Agasa" << endl;

    return 0;
}
