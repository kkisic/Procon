#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<P> p(m);
    vector<int> room(n+2);
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        p[i] = make_pair(s, t);
        room[s]++;
        room[t+1]--;
    }

    for(int i = 1; i < n+2; i++){
        room[i] += room[i-1];
    }

    for(int i = 0; i < n+2; i++){
        if(room[i] != 1){
            room[i] = 0;
        }
    }

    for(int i = 1; i < n+2; i++){
        room[i] += room[i-1];
    }

    vector<int> ans;
    for(int i = 0; i < m; i++){
        if(room[p[i].second] - room[p[i].first-1] == 0){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
