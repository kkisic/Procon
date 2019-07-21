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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> last;
    rep(i, n){
        if(last.find(a[i]) != last.end()){
            continue;
        }
        last[a[i]] = n + i;
    }

    vector<int> nxt(n);
    for(int i = n - 1; i >= 0; i--){
        nxt[i] = last[a[i]] + 1;
        last[a[i]] = i;
    }

    for(int i = n - 1; i >= 0; i--){
        if(nxt[i] >= n){
            continue;
        }
        nxt[i] = nxt[nxt[i]];
    }
    rep(i, n){
        if(nxt[i] >= n){
            nxt[i] -= n;
        }
    }

    int cnt = 0;
    int pos = 0;
    do{
        pos = nxt[pos];
        cnt++;
        if(pos >= n){
            pos -= n;
            cnt++;
        }
    }while(pos != 0);

    k = (k - 1) % cnt;
    pos = 0;
    while(k > 0){
        pos = nxt[pos];
        k--;
        if(pos >= n){
            pos -= n;
            k--;
        }
    }

    if(k == -1){
        cout << endl;
        return 0;
    }

    map<int, int> m;
    stack<int> st;
    for(int i = pos; i < n; i++){
        if(m.find(a[i]) == m.end() || m[a[i]] == 0){
            m[a[i]]++;
            st.push(a[i]);
            continue;
        }
        while(m[a[i]] > 0){
            m[st.top()]--;
            st.pop();
        }
    }

    vector<int> ans;
    while(not st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ALL(ans));
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
