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
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    bool even = false;
    bool odd = false;
    rep(i, n){
        if((abs(x[i]) + abs(y[i])) % 2 == 0){
            even = true;
        }
        if((abs(x[i]) + abs(y[i])) % 2 == 1){
            odd = true;
        }
    }
    if(even && odd){
        cout << -1 << endl;
        return 0;
    }

    vector<int> d;
    for(int i = 32; i >= 0; i--){
        d.push_back(pow(2, i));
    }
    if(even){
        d.push_back(1);
    }

    int m = d.size();

    cout << m << endl;
    rep(i, m-1){
        cout << d[i] << " ";
    }
    cout << d[m-1] << endl;

    rep(i, n){
        vector<int> s = {x[i] + y[i], x[i] - y[i]};

        vector<vector<int>> dd(2, vector<int>(m));
        rep(i, 2){
            int dist = 0;
            rep(j, m){
                if(abs(dist + d[j] - s[i]) < abs(dist - d[j] - s[i])){
                    dist += d[j];
                    dd[i][j] = 0;
                }else{
                    dist -= d[j];
                    dd[i][j] = 1;
                }
            }
        }

        string ans = "";
        rep(j, m){
            if(dd[0][j] == 0 && dd[0][j] == dd[1][j]){
                ans.push_back('R');
            }
            if(dd[0][j] == 1 && dd[0][j] == dd[1][j]){
                ans.push_back('L');
            }
            if(dd[0][j] == 0 && dd[0][j] != dd[1][j]){
                ans.push_back('U');
            }
            if(dd[0][j] == 1 && dd[0][j] != dd[1][j]){
                ans.push_back('D');
            }
        }

        cout << ans << endl;
    }

    return 0;
}
