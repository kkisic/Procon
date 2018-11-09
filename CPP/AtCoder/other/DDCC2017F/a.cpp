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

    int k;
    cin >> k;

    vector<int> l = {200, 300};
    vector<int> ans;
    for(int r : l){
        int n = r / k;
        int tmp = 0;

        if(n % 2 == 0){
            for(int i = k; i <= r / 2; i += k){
                for(int j = k; j <= r / 2; j += k){
                    double dist = pow(i, 2) + pow(j, 2);
                    if(dist <= pow(r / 2, 2)){
                        tmp++;
                    }
                }
            }
            tmp *= 4;
        }else{
            for(double i = k + k / 2.0; i <= r / 2; i += k){
                for(double j = k + k / 2.0; j <= r / 2; j += k){
                    double dist = pow(i, 2) + pow(j, 2);
                    if(dist <= pow(r / 2, 2)){
                        tmp++;
                    }
                }
            }
            tmp *= 4;
            tmp += n * 2 - 5;
        }
        ans.push_back(tmp);
    }

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
