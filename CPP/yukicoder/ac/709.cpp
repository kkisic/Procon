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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> win(m, vector<int>());
    vector<int> max(m, 0);
    vector<int> cnt(n+1, 0);
    int ans = 0;
    rep(i, n){
        rep(j, m){
            int r;
            cin >> r;

            if(max[j] < r){
                for(int k: win[j]){
                    cnt[k]--;
                    if(cnt[k] == 0){
                        ans--;
                    }
                }

                max[j] = r;
                win[j] = vector<int>();
                win[j].push_back(i);
                cnt[i]++;
                if(cnt[i] == 1){
                    ans++;
                }
                continue;
            }
            if(max[j] == r){
                win[j].push_back(i);
                cnt[i]++;
                if(cnt[i] == 1){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
