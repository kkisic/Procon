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

    int l, r;
    l = r = 0;
    map<int, int> lm, rm;
    rep(i, n){
        char c;
        int id;
        cin >> c >> id;

        if(c == 'L'){
            lm.emplace(id, ++l);
        }
        if(c == 'R'){
            rm.emplace(id, ++r);
        }
        if(c == '?'){
            int ll, rr;
            if(lm.find(id) != lm.end()){
                ll = l - lm[id];
            }else{
                ll = rm[id] + l - 1;
            }

            if(rm.find(id) != rm.end()){
                rr = r - rm[id];
            }else{
                rr = lm[id] + r - 1;
            }
            cout << min(ll, rr) << endl;
        }
    }

    return 0;
}
