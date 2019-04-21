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

    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;

    vector<int> x(m), y(m);
    rep(i, m){
        cin >> x[i] >> y[i];
        y[i] = n - y[i];
    }
    x.push_back(p - 1);
    y.push_back(n - q);

    deque<P> deq;
    deq.emplace_back(1, n);

    rep(i, m + 1){
        queue<P> top, bottom;
        int cnt;

        cnt = 0;
        while(cnt < x[i]){
            int len = deq.front().second - deq.front().first + 1;

            if(len <= x[i] - cnt){
                cnt += len;
                top.push(deq.front());
                deq.pop_front();
            }else{
                int nxt = deq.front().first + x[i] - cnt;
                cnt = x[i];
                top.emplace(deq.front().first, nxt - 1);
                deq.front().first = nxt;
            }
        }

        cnt = 0;
        while(cnt < y[i]){
            int len = deq.back().second - deq.back().first + 1;

            if(len <= y[i] - cnt){
                cnt += len;
                bottom.push(deq.back());
                deq.pop_back();
            }else{
                int nxt = deq.back().second - (y[i] - cnt);
                cnt = y[i];
                bottom.emplace(nxt + 1, deq.back().second);;
                deq.back().second = nxt;
            }
        }

        if(i == m){
            break;
        }

        while(not top.empty()){
            deq.push_back(top.front());
            top.pop();
        }
        while(not bottom.empty()){
            deq.push_front(bottom.front());
            bottom.pop();
        }
    }

    int ans = 0;
    while(not deq.empty()){
        int tmp = min(r, deq.front().second) + 1 - deq.front().first;
        deq.pop_front();
        if(tmp > 0){
            ans += tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
