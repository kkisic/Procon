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

    int i;
    bool mon = false;
    for(i = 6; i * i <= n;){
        int next;
        if(mon){
            next = i + 5;
            mon = false;
        }else{
            next = i + 2;
            mon = true;
        }

        if(!x[i]){
            i = next;
            continue;
        }

        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
        i = next;
    }

    for(; i <= n;i++){
        if(x[i] && (i % 7 == 1 || i % 7 == 6)){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    vector<int> p = prime(300000);


    while(true){
        int n;
        cin >> n;

        if(n == 1){
            break;
        }

        cout << n << ":";
        rep(i, (int)p.size()){
            if(n % p[i] == 0){
                cout << " " << p[i];
            }
        }
        cout << endl;
    }

    return 0;
}
