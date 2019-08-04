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

    string s;
    cin >> s;

    int n = SZ(s);
    //vector<P> l, r;
    vector<int> ans(n);

    int l, r;
    int cntR = 0;
    int cntL = 0;
    bool isR = true;
    rep(i, n){
        if(s[i] == 'R'){
            if(isR){
                r = i;
            }else{
                isR = true;

                int sum = cntR + cntL;
                ans[l] = ans[r] = sum / 2;
                if(sum % 2){
                    if(cntR > cntL){
                        ans[r]++;
                    }else{
                        ans[l]++;
                    }
                }

                if((max(cntR, cntL) - 1) % 2){
                    swap(ans[l], ans[r]);
                }

                cntR = 0;
                cntL = 0;
                r = i;
            }
            cntR++;
        }else{
            if(isR){
                l = i;
                isR = false;
            }
            cntL++;
        }
    }
    int sum = cntR + cntL;
    ans[l] = ans[r] = sum / 2;
    if(sum % 2){
        if(cntR > cntL){
            ans[r]++;
        }else{
            ans[l]++;
        }
    }

    if((max(cntR, cntL) - 1) % 2){
        swap(ans[l], ans[r]);
    }

    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
