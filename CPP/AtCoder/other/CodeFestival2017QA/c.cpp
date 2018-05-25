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

signed main(){
    int h, w;
    cin >> h >> w;

    vector<int> a(26);
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            a[c-'a']++;
        }
    }

    int once = h * w % 2;
    int twice = 0;
    if(h % 2 == 1){
        twice += w / 2;
    }
    if(w % 2 == 1){
        twice += h / 2;
    }
    int other = (h / 2) * (w / 2);

    rep(i, once){
        rep(j, 26){
            if(a[j] % 4 == 1 || a[j] % 4 == 3){
                a[j] -= 1;
                break;
            }
        }
    }

    int cnt = 0;
    rep(i, twice){
        rep(j, 26){
            if(a[j] < 2){
                continue;
            }
            if(a[j] % 4 == 2){
                a[j] -= 2;
                cnt++;
                break;
            }
        }
    }

    if((twice - cnt) % 2 == 1){
        cout << "No" << endl;
        return 0;
    }

    rep(i, other+(twice - cnt)/2){
        rep(j, 26){
            if(a[j] < 4){
                continue;
            }
            if(a[j] % 4 == 0){
                a[j] -= 4;
                break;
            }
        }
    }

    rep(i, 26){
        if(a[i] != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
