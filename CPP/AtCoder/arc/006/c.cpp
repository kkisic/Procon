#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<int> a;
    rep(i, n){
        int w;
        cin >> w;

        if(a.size() == 0){
            a.push_back(w);
            continue;
        }

        bool f = true;
        rep(j, (int)a.size()){
            if(a[j] < w){
                continue;
            }
            a[j] = w;
            f = false;
            break;
        }
        if(f){
            a.push_back(w);
        }
    }
    cout << a.size() << endl;

    return 0;
}
