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
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    set<int> as;
    rep(i, k){
        cin >> a[i];
        as.insert(a[i]);
    }

    vector<string> s(n+1);
    rep(i, n) cin >> s[i+1];

    int len = INF;
    rep(i, k){
        int tmp = s[a[i]].length();
        if(tmp < len){
            len = tmp;
        }
    }

    string ans = "";
    rep(i, len){
        char c = s[a[0]][i];
        bool ok = true;
        for(int j = 1; j < k; j++){
            if(c != s[a[j]][i]){
                ok = false;
            }
        }
        if(!ok){
            break;
        }
        ans.push_back(c);
    }

    string ansSub;
    rep(i, (int)ans.length()+1){
        bool ok = true;

        ansSub = ans.substr(0, i);
        for(int j = 1; j <= n; j++){
            string sub = s[j].substr(0, i);
            if(ansSub == sub && as.find(j) == as.end()){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << ansSub << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
