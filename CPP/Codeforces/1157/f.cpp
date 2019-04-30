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

    int n;
    cin >> n;
    vector<int> a(200001);
    rep(i, n){
        int x;
        cin >> x;
        a[x]++;
    }

    int head = -1;
    vector<P> r;
    for(int i = 1; i <= 200000; i++){
        if(head != -1){
            if(a[i] == 0){
                r.emplace_back(head, i - 1);
                head = -1;
            }else if(a[i] == 1){
                r.emplace_back(head, i);
                head = i;
            }else{
                continue;
            }
        }
        if(head == -1){
            if(a[i] == 0){
                continue;
            }
            head = i;
        }
    }
    if(head != -1){
        r.emplace_back(head, 200000);
    }

    int idx = -1;
    int len = 0;
    rep(i, SZ(r)){
        int tmp = 0;
        for(int j = r[i].first; j <= r[i].second; j++){
            tmp += a[j];
        }
        if(len < tmp){
            len = tmp;
            idx = i;
        }
    }

    vector<int> ans;
    for(int i = r[idx].first; i <= r[idx].second; i++){
        ans.push_back(i);
        a[i]--;
    }
    for(int i = r[idx].second; i >= r[idx].first; i--){
        rep(j, a[i]){
            ans.push_back(i);
        }
    }

    cout << SZ(ans) << endl;
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
