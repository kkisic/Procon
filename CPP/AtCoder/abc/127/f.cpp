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

    int q;
    cin >> q;

    priority_queue<int> lt;
    priority_queue<int, vector<int>, greater<int>> gt;
    int ls = 0;
    int gs = 0;
    int sum = 0;
    rep(i, q){
        int x;
        cin >> x;

        if(x == 2){
            int ans = lt.top() * SZ(lt) - ls - lt.top() * SZ(gt) + gs;
            cout << lt.top() << " " << ans + sum << endl;

            continue;
        }
        int a, b;
        cin >> a >> b;
        sum += b;

        if(lt.empty() || lt.top() >= a){
            lt.push(a);
            ls += a;
        }else{
            gt.push(a);
            gs += a;
        }
        while(SZ(lt) - SZ(gt) > 1){
            gt.push(lt.top());
            gs += lt.top();
            ls -= lt.top();
            lt.pop();
        }
        while(SZ(lt) - SZ(gt) < 0){
            lt.push(gt.top());
            ls += gt.top();
            gs -= gt.top();
            gt.pop();
        }
    }

    return 0;
}
