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

    int sum = 0;
    rep(i, SZ(s)){
        sum += s[i] - '0';
    }

    vector<int> ans;
    while(sum > 0){
        if(sum >= 9){
            ans.push_back(9);
            sum -= 9;
        }else{
            ans.push_back(sum);
            sum = 0;
        }
    }

    int x = SZ(ans);
    if(ans[x-1] == s[0] - '0' && x == SZ(s)){
        if(ans[x-1] != 9){
            if(x > 1){
                ans[x-1]++;
                ans[x-2]--;
            }else{
                ans[x-1]--;
                ans.push_back(1);
            }
        }else{
            ans[x-1]--;
            ans.push_back(1);
        }
    }

    for(int i = SZ(ans) - 1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
