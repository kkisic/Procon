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

template <typename T>
void debugv(vector<T>& vec){
    for(T t : vec){
        cout << t << endl;
    }
    cout << endl;
}

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> h(n+1, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        h[a].push_back(b);
    }

    int up, right;
    up = right = 1;
    vector<vector<P>> ans(n+1, vector<P>());
    for(int i = 1; i <= n; i++){
        if(h[i].size() == 0){
            ans[i].emplace_back(right, i);
            right++;
            continue;
        }
        rep(j, (int)h[i].size()){
            ans[i].emplace_back(right, i);
            ans[h[i][j]].emplace_back(right, h[i][j]);
            right++;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i].size() << endl;
        rep(j, (int)ans[i].size()){
            cout << ans[i][j].first << " " << ans[i][j].second << endl;
        }
    }

    return 0;
}
