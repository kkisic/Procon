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

    map<char, char> m;
    rep(i, n){
        char a, b;
        cin >> a >> b;
        m[a] = b;
    }

    int x;
    cin >> x;
    rep(i, x){
        char c;
        cin >> c;

        if(m.find(c) != m.end()){
            c = m[c];
        }
        cout << c;
    }
    cout << endl;

    return 0;
}
