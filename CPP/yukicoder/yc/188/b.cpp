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
    string s;
    cin >> s;

    vector<int> diff(s.length()+1);

    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'A'){
            diff[i+1] = diff[i] + 1;
        }
        if(s[i] == 'B'){
            diff[i+1] = diff[i] - 1;
        }
    }

    map<int, vector<int>> m;

    rep(i, (int)s.length()+1){
        if(m.find(diff[i]) == m.end()){
            m.emplace(diff[i], vector<int>());
        }
        m[diff[i]].push_back(i);
    }

    int ans = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        vector<int> v = (*it).second;
        sort(v.begin(), v.end());
        int tmp = v[v.size()-1] - v[0];
        if(tmp > ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
