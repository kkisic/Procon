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

    vector<tuple<int, int, int>> x(n * 2);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        x[i*2] = make_tuple(a, i, 0);
        x[i*2+1] = make_tuple(b, i, 1);
    }
    sort(x.begin(), x.end());

    bool a, b; //A, Bを使ったか
    a = b = false;
    int ans = 0;
    bool dup = false; //A, Bの両方を使う頂点があるか
    set<int> s;
    rep(i, n){
        int id = get<1>(x[i]);
        if(s.find(id) != s.end()){
            dup = true;
        }
        s.insert(id);

        int type = get<2>(x[i]);
        if(type){
            b = true;
        }else{
            a = true;
        }

        ans += get<0>(x[i]);
    }

    //Bのみ or Aのみ or ABを両方使う頂点が一つ以上
    if(not a || not b || dup){
        cout << ans << endl;
        return 0;
    }

    ans = 0;
    s = set<int>();
    dup = false;
    rep(i, n-1){
        s.insert(get<1>(x[i]));
        ans += get<0>(x[i]);
    }

    //n-1個目を飛ばしたらOK
    if(s.find(get<1>(x[n])) != s.end()){
        cout << ans + get<0>(x[n]) << endl;
        return 0;
    }

    ans -= get<0>(x[n-2]);

    //n-1個目とn個目が同じ頂点の場合
    //n-1個目, n個目を飛ばす or n-2個目を飛ばす
    ans = min(ans + get<0>(x[n-2]) + get<0>(x[n+1]), ans + get<0>(x[n-1]) + get<0>(x[n]));
    cout << ans << endl;

    return 0;
}
