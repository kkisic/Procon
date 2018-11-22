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
    map<int, int> m;
    rep(i, n){
        cin >> a[i];
        if(m.find(a[i]) == m.end()){
            m[a[i]] = 0;
        }
        m[a[i]]++;
    }


    vector<int> s(n+1);
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    vector<int> ans;
    rep(i, n){
        int sum = s[i] + s[n] - s[i+1];

        if(sum % 2 != 0){
            continue;
        }

        int x = sum / 2;

        if(a[i] == x){
            if(m[x] > 1){
                ans.push_back(i+1);
            }
        }else{
            if(m[x] > 0){
                ans.push_back(i+1);
            }
        }
    }

    cout << SZ(ans) << endl;
    if(SZ(ans) > 0){
        cout << ans[0];
        for(int i = 1; i < SZ(ans); i++){
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}
