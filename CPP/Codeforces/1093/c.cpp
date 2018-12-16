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
    n /= 2;
    vector<int> b(n);
    rep(i, n) cin >> b[i];

    queue<int> fst;
    stack<int> snd;
    int x = 0;
    int y = b[0];
    fst.push(x);
    snd.push(y);
    for(int i = 1; i < n; i++){
        if(b[i-1] >= b[i]){
            y -= b[i-1] - b[i];
            fst.push(x);
            snd.push(y);
            continue;
        }
        x += b[i] - b[i-1];
        fst.push(x);
        snd.push(y);
    }

    rep(i, n){
        cout << fst.front() << " ";
        fst.pop();
    }
    rep(i, n-1){
        cout << snd.top() << " ";
        snd.pop();
    }
    cout << snd.top() << endl;

    return 0;
}
