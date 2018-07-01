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
    vector<int> s3;
    rep(i, 1e6){
        if(i == 0){
            s3.push_back(0);
            continue;
        }
        s3.push_back(s3[i-1] + i);
        if(s3[i] >= 1e6){
            break;
        }
    }


    vector<int> s4;
    for(int i = 0; s3[i] < 1e6; i++){
        if(i == 0){
            s4.push_back(0);
            continue;
        }
        s4.push_back(s4[i-1] + s3[i]);
        if(s4[i] > 1e6){
            break;
        }
    }

    int n = (int)s4.size();
    vector<int> dp1(1e6, INF);
    dp1[0] = 0;
    for(int i = 1; i < n; i++){
        rep(j, 1e6){
            if(j + s4[i] >= 1e6 || dp1[j] == INF){
                continue;
            }
            dp1[j + s4[i]] = min(dp1[j + s4[i]], dp1[j] + 1);
        }
    }

    vector<int> dp2(1e6, INF);
    dp2[0] = 0;
    for(int i = 1; i < n; i++){
        if(s4[i] % 2 == 0){
            continue;
        }
        rep(j, 1e6){
            if(j + s4[i] >= 1e6 || dp2[j] == INF){
                continue;
            }
            dp2[j + s4[i]] = min(dp2[j + s4[i]], dp2[j] + 1);
        }
    }

    while(true){
        int x;
        cin >> x;

        if(x == 0){
            break;
        }
        cout << dp1[x] << " " << dp2[x] << endl;
    }

    return 0;
}
