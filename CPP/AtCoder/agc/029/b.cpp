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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(ALL(a));
    map<int, queue<int>> m;
    rep(i, n){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = queue<int>();
        }
        m[a[i]].push(i);
    }

    vector<int> two;
    two.push_back(1);
    rep(i, 30){
        two.push_back(two[i] * 2);
    }

    int ans = 0;
    vector<bool> used(n, false);
    for(int i = n - 1; i >= 0; i--){
        if(used[i]){
            continue;
        }
        rep(j, 31){
            int dst = two[j] - a[i];
            int ok = false;
            if(m.find(dst) == m.end()){
                continue;
            }
            int head = m[dst].front();
            while(not m[dst].empty()){
                int idx = m[dst].front();
                m[dst].pop();

                if(used[idx] || idx == i){
                    m[dst].push(idx);
                    if(m[dst].front() == head){
                        break;
                    }
                    continue;
                }
                ans++;
                used[idx] = true;
                used[i] = true;
                ok = true;
                break;
            }
            if(ok){
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
