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

void solve(vector<bool>& t, vector<int>& d, vector<int>& ans, int i){
    if(i > 12){
        vector<int> s;
        for(int j = 0; j < 24; j++){
            if(t[j]){
                s.push_back(j);
            }
        }
        int minT = INF;
        for(int j = 0; j < (int)s.size()-1; j++){
            for(int k = j+1; k < (int)s.size(); k++){
                int time = s[k] - s[j];
                time = min(time, 24 - time);
                if(time < minT){
                    minT = time;
                }
            }
        }
        ans.push_back(minT);
        return ;
    }

    if(d[i] == 0){
        solve(t, d, ans, i+1);
    }else{
        t[i] = true;
        solve(t, d, ans, i+1);
        t[i] = false;
        t[24-i] = true;
        solve(t, d, ans, i+1);
        t[24-i] = false;
    }
}

signed main(){
    int n;
    cin >> n;

    vector<int> d(13);
    d[0] = 1;
    rep(i, n){
        int x;
        cin >> x;
        d[x]++;
    }

    vector<bool> t(24, false);
    for(int i = 1; i <= 12; i++){
        if(d[i] == 2){
            t[i] = true;
            t[24-i] = true;
            d[i] = 0;
        }
        if(d[i] > 2){
            cout << 0 << endl;
            return 0;
        }
    }

    if(d[0] == 1){
        t[0] = true;
    }

    if(d[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;
    solve(t, d, ans, 1);

    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}
