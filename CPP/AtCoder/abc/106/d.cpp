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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

//a[s][t] = 0 <= i < s, 0 <= j < t
template <typename T>
class cumulative{
    public:
        int h, w;
        vector<vector<T>> c, a;

        cumulative(const vector<vector<T>>& c, int h, int w)
            : h(h), w(w), c(c), a(h+1, vector<T>(w+1)) {
                for(int i = 1; i <= h; i++){
                    for(int j = 1; j <= w; j++){
                        a[i][j] += c[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                    }
                }
            }

        T query(int i, int j, int k, int l){
            return a[k][l] - a[k][j] - a[i][l] + a[i][j];
        }
};

signed main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n+1, vector<int>(n+1));
    rep(i, m){
        int l, r;
        cin >> l >> r;
        a[l][r]++;
    }

    cumulative<int> c(a, n+1, n+1);
    rep(i, q){
        int s, t;
        cin >> s >> t;
        cout << c.query(s, s, t+1, t+1) << endl;
    }

    return 0;
}
