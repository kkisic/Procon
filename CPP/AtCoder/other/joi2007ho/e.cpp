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

struct Bar{
    int p, q, r, b;
};

int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int dfs(vector<Bar>& bar, int v){
    int R = -1;
    if(bar[v].r != 0){
        R = dfs(bar, bar[v].r);
    }
    int B = -1;
    if(bar[v].b != 0){
        B = dfs(bar, bar[v].b);
    }

    if(R != -1 && B != -1){
        int pr = bar[v].p * R;
        int qb = bar[v].q * B;
        int g = gcd(pr, qb);
        int lcm = pr * qb / g;
        R = lcm / bar[v].p;
        B = lcm / bar[v].q;
    }

    if(R == -1 && B == -1){
        R = bar[v].q;
        B = bar[v].p;
    }
    if(R == -1){
        int qb = bar[v].q * B;
        int g = gcd(bar[v].p, qb);
        int lcm = bar[v].p * qb / g;
        R = lcm / bar[v].p;
        B = lcm / bar[v].q;
    }
    if(B == -1){
        int pr = bar[v].p * R;
        int g = gcd(bar[v].q, pr);
        int lcm = bar[v].q * pr / g;
        R = lcm / bar[v].p;
        B = lcm / bar[v].q;
    }
    return R + B;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Bar> bar(n + 1);
    vector<bool> used(n + 1, false);
    rep(i, n){
        int p, q, r, b;
        cin >> p >> q >> r >> b;
        int g = gcd(p, q);
        bar[i+1] = Bar{p / g, q / g, r, b};
        used[r] = used[b] = true;
    }

    int root = -1;
    rep(i, n + 1){
        if(not used[i]){
            root = i;
        }
    }
    cout << dfs(bar, root) << endl;

    return 0;
}
