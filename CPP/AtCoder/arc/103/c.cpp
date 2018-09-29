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
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    vector<P> s(100001), t(100001);
    rep(i, 100001){
        s[i] = make_pair(0, i);
        t[i] = make_pair(0, i);
    }
    rep(i, n){
        if(i % 2 == 0){
            s[v[i]].first++;
        }else{
            t[v[i]].first++;
        }
    }
    sort(s.begin(), s.end(), greater<P>());
    sort(t.begin(), t.end(), greater<P>());
    int ans1 = s[0].first;
    if(s[0].second == t[0].second){
        ans1 += t[1].first;
    }else{
        ans1 += t[0].first;
    }
    int ans2 = t[0].first;
    if(s[0].second == t[0].second){
        ans2 += s[1].first;
    }else{
        ans2 += s[0].first;
    }

    cout << n - max(ans1, ans2) << endl;


    return 0;
}
