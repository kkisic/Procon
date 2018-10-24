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

vector<int> gaussian_bit(vector<int> a, int k){
    int n = a.size();
    set<int> as;

    rep(i, k){
        int axis = -1;
        rep(j, n){
            if((a[j] >> i) % 2 == 1 && as.find(j) == as.end()){
                axis = j;
                as.insert(j);
                break;
            }
        }

        if(axis == -1){
            continue;
        }

        rep(j, n){
            if(j == axis){
                continue;
            }
            if((a[j] >> i) % 2 == 1){
                a[j] ^= a[axis];
            }
        }
    }
    sort(a.begin(), a.end());

    return a;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<int> aa = gaussian_bit(a, 60);
    vector<int> bb = gaussian_bit(b, 60);

    rep(i, n){
        if(aa[i] != bb[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
