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
    deque<int> a;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }

    int now = 0;
    string ans;
    while(now < a.front() || now < a.back()){
        if(a.front() == a.back() && SZ(a) > 3){
            int l = 1;
            rep(i, SZ(a)){
                if(a[i] >= a[i+1]){
                    break;
                }
                l++;
            }

            int r = 1;
            for(int i = SZ(a) - 1; i >= 0; i--){
                if(a[i-1] <= a[i]){
                    break;
                }
                r++;
            }

            if(l > r){
                rep(i, l){
                    ans.push_back('L');
                }
            }else{
                rep(i, r){
                    ans.push_back('R');
                }
            }
            break;
        }

        int side = 0;
        int nxt = INF;
        if(now < a.front()){
            side = -1;
            nxt = min(nxt, a.front());
        }
        if(now < a.back()){
            if(nxt > a.back()){
                side = 1;
                nxt = min(nxt, a.back());
            }
        }
        if(side == -1){
            ans.push_back('L');
            a.pop_front();
        }else{
            ans.push_back('R');
            a.pop_back();
        }
        now = nxt;

        if(a.empty()){
            break;
        }
    }

    cout << SZ(ans) << endl;
    cout << ans << endl;

    return 0;
}
