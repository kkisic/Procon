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

    int s;
    cin >> s;

    set<int> ss;
    ss.insert(s);
    vector<int> a(1e6 + 10);
    a[1] = s;
    int i = 2;
    while(true){
        if(a[i-1] % 2){
            a[i] = (a[i-1] * 3 + 1);
        }else{
            a[i] = (a[i-1] / 2);
        }
        if(ss.find(a[i]) != ss.end()){
            cout << i << endl;
            return 0;
        }
        ss.insert(a[i]);
        i++;
    }

    return 0;
}
