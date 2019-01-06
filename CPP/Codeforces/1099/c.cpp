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
    int k;
    cin >> s >> k;

    int len = 0;
    int candy, snow;
    candy = snow = 0;
    rep(i, SZ(s)){
        if(s[i] == '?'){
            candy++;
            continue;
        }
        if(s[i] == '*'){
            snow++;
            continue;
        }
        len++;
    }

    int mini = len - candy - snow;
    int maxi = len;
    if(snow > 0){
        maxi = INF;
    }

    if(k < mini || maxi < k){
        cout << "Impossible" << endl;
        return 0;
    }

    string ans;
    if(k <= len){
        int diff = len - k;
        for(int i = SZ(s) - 1; i >= 0; i--){
            if(s[i] == '?' || s[i] == '*'){
                if(diff > 0){
                    i--;
                    diff--;
                }
                continue;
            }
            ans.push_back(s[i]);
        }
        reverse(ALL(ans));
    }else{
        int diff = k - len;
        for(int i = SZ(s) - 1; i >= 0; i--){
            if(s[i] == '?'){
                continue;
            }
            if(s[i] == '*'){
                rep(j, diff){
                    ans.push_back(s[i-1]);
                }
                diff = 0;
                continue;
            }
            ans.push_back(s[i]);
        }
        reverse(ALL(ans));
    }
    cout << ans << endl;

    return 0;
}
