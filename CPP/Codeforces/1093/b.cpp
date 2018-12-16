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

    int t;
    cin >> t;
    rep(k, t){
        string s;
        cin >> s;
        bool pass = false;

        int len = SZ(s);
        set<char> cs;
        rep(i, len / 2){
            cs.insert(s[i]);
            if(s[i] != s[len-1-i]){
                cout << s << endl;
                pass = true;
                break;
            }
        }
        cs.insert(s[len/2]);

        if(pass){
            continue;
        }

        if(cs.size() == 1){
            cout << -1 << endl;
            continue;
        }

        rep(i, len){
            if(s[0] != s[i]){
                swap(s[0], s[i]);
                break;
            }
        }
        cout << s << endl;
    }

    return 0;
}
