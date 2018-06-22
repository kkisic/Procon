#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

void solve(int n){
    vector<char> c(n);
    map<char, int> mI;
    map<int, char> mC;
    int id = 0;
    rep(i, n) {
        cin >> c[i];

        if(mI.find(c[i]) == mI.end()){
            mI.emplace(c[i], id);
            mC.emplace(id++, c[i]);
        }
    }

    int num = mI.size();

    if(num == 1){
        cout << mC[0] << " " << n / 2 + 1 << endl;
        return;
    }

    vector<int> v(num);
    rep(i, n){
        v[mI[c[i]]]++;

        rep(s, num){

            bool win = true;
            rep(t, num){
                if(s == t){
                    continue;
                }

                if(v[s] <= v[t] + n - i - 1){
                    win = false;
                }
            }
            if(win){
                cout << mC[s] << " " << i+1 << endl;
                return;
            }
        }
    }
    cout << "TIE" << endl;
}

signed main(){
    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }
        solve(n);
    }

    return 0;
}
