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
    vector<P> v;
    rep(i, n){
        int x;
        cin >> x;
        if(i == 0 || v.back().first != x){
            v.emplace_back(x, 0);
        }
        v.back().second++;
    }

    int ans = 0;
    rep(i, SZ(v)){
        if(v[i].second != 1){
            continue;
        }

        int cur = 0;
        int limit = min(i, SZ(v) - i);
        for(int j = 1; j <= limit; j++){
            if(v[i-j].first == v[i+j].first){
                int tmp = 0;
                tmp += v[i-j].second;
                tmp += v[i+j].second;
                if(j == 1){
                    tmp++;
                }
                if(tmp >= 4){
                    cur += tmp;
                }else{
                    break;
                }
                continue;
            }
            break;
        }
        ans = max(ans, cur);
    }

    rep(i, SZ(v)){
        if(v[i].second != 3){
            continue;
        }
        if(i == 0 || i == SZ(v) - 1){
            ans = max(ans, 4LL);
            continue;
        }

        int l = i - 1;
        int r = i + 1;
        int cur = 4;
        int bias = 1;
        if(i > 0){
            if(v[l].second == 1){
                l--;
                bias = 0;
            }
        }

        while(l >= 0 && r < SZ(v)){
            if(v[l].first == v[r].first){
                int tmp = 0;
                tmp += v[l].second - bias;
                tmp += v[r].second;
                if(tmp >= 4){
                    cur += tmp;
                }else{
                    break;
                }
                l--;
                r++;
                bias = 0;
                continue;
            }
            break;
        }
        ans = max(ans, cur);
    }

    rep(i, SZ(v)){
        if(v[i].second != 3){
            continue;
        }
        if(i == 0 || i == SZ(v) - 1){
            ans = max(ans, 4LL);
            continue;
        }

        int l = i - 1;
        int r = i + 1;
        int cur = 4;
        int bias = 1;
        if(i < SZ(v) - 1){
            if(v[r].second == 1){
                r++;
                bias = 0;
            }
        }

        while(l >= 0 && r < SZ(v)){
            if(v[l].first == v[r].first){
                int tmp = 0;
                tmp += v[l].second;
                tmp += v[r].second - bias;
                if(tmp >= 4){
                    cur += tmp;
                }else{
                    break;
                }
                l--;
                r++;
                bias = 0;
                continue;
            }
            break;
        }
        ans = max(ans, cur);
    }

    cout << n - ans << endl;

    return 0;
}
