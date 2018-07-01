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

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    while(true){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        if(n <= 2){
            cout << 1 << endl;
            continue;
        }

        vector<int> p = prime(n);
        vector<int> q = prime(n * 2);

        cout << q.size() - p.size() << endl;
    }

    return 0;
}
