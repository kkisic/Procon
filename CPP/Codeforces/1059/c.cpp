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

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    if(n == 3){
        cout << "1 1 3" << endl;
        return 0;
    }

    int m = 2;
    vector<int> div;
    while(m <= n){
        div.push_back(n / m);
        m *= 2;
    }
    div.push_back(0);

    int re = n;
    int i = 0;
    vector<int> ans;
    while(re > 0){
        int tmp = re - div[i];
        rep(j, tmp){
            ans.push_back(pow(2, i));
        }
        re -= tmp;
        i++;
    }

    int imax;
    for(int i = div.size() - 1; i >= 0; i--){
        if(div[i] == 0){
            continue;
        }
        imax = i;
        break;
    }

    if(pow(2, imax+1) < n){
        int tmp = n / pow(2, imax);
        ans[n-1] = tmp * pow(2, imax);
    }

    rep(i, n-1){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;

    return 0;
}
