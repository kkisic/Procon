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
    vector<bool> used(2020, false);
    vector<int> x(n+1);
    rep(i, n){
        cin >> x[i+1];
        used[x[i+1]] = true;
    }

    int m;
    cin >> m;
    rep(i, m){
        int a;
        cin >> a;

        if(used[x[a]+1]){
            continue;
        }
        if(x[a] == 2019){
            continue;
        }
        used[x[a]] = false;
        used[x[a]+1] = true;
        x[a]++;
    }

    for(int i = 1; i <= 2019; i++){
        if(used[i]){
            cout << i << endl;
        }
    }

    return 0;
}
