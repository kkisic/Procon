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

    int x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);

    if(x == 0 && y == 0){
        cout << "Yes" << endl;
        return 0;
    }

    vector<int> c(4);
    rep(i, SZ(s)){
        c[s[i]-'W']++;

        rep(j, (1LL << 4)){
            if(__builtin_popcount(j) != 2){
                continue;
            }
            int nx = 0, ny = 0;
            rep(k, 4){
                if((j >> k) % 2 == 1){
                    if(nx == 0){
                        nx += c[k];
                    }else{
                        nx -= c[k];
                    }
                }else{
                    if(ny == 0){
                        ny += c[k];
                    }else{
                        ny -= c[k];
                    }
                }
            }
            nx = abs(nx);
            ny = abs(ny);

            if(nx == x && ny == y){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
