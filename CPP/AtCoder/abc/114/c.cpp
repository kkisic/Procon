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

    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(7);
    vector<int> ans;
    vector<int> a = {3, 5, 7};
    while(not st.empty()){
        int x = st.top();
        st.pop();

        if(x > n){
            continue;
        }
        ans.push_back(x);

        rep(i, 3){
            st.push(x * 10 + a[i]);
        }
    }

    int cnt = 0;
    for(int x : ans){
        bool is[8] = {};

        while(x != 0){
            is[x%10] = true;
            x /= 10;
        }

        if(is[3] && is[5] && is[7]){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
