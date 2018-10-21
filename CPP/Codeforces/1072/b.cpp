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

template <typename T>
void debugv(vector<T>& vec){
    for(T t : vec){
        cout << t << endl;
    }
    cout << endl;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n-1), b(n-1);
    rep(i, n-1) cin >> a[i];
    rep(i, n-1) cin >> b[i];

    // a: or, b: and
    vector<int> t;
    rep(i, 4){
        t = vector<int>(n, -1);
        t[0] = i;

        for(int j = 0; j < n-1; j++){
            if(t[j] == -1){
                continue;
            }
            rep(k, 4){
                if((t[j] | k) == a[j] && (t[j] & k) == b[j]){
                    t[j+1] = k;
                }
            }
        }
        if(t[n-1] != -1){
            break;
        }
    }

    if(t[n-1] == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    rep(i, n-1){
        cout << t[i] << " ";
    }
    cout << t[n-1] << endl;

    return 0;
}
