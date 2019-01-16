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
    string s;
    cin >> n >> s;
    vector<int> c(3, - n / 3);
    rep(i, n){
        c[s[i]-'0']++;
    }

    rep(i, 2){
        rep(j, n){
            if(c[i] >= 0){
                break;
            }
            int id = s[j] - '0';
            if(c[id] > 0 && id > i){
                s[j] = '0' + i;
                c[i]++;
                c[id]--;
            }
        }
    }

    for(int i = 2; i > 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(c[i] >= 0){
                break;
            }
            int id = s[j] - '0';
            if(c[id] > 0 && id < i){
                s[j] = '0' + i;
                c[i]++;
                c[id]--;
            }
        }
    }

    cout << s << endl;

    return 0;
}
