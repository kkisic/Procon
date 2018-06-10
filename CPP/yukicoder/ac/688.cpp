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
    int k;
    cin >> k;

    if(k == 0){
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }

    for(int a = 0; a <= 30; a++){
        for(int b = 2; b <= 30 - a; b++){
            int p = pow(2, a) * b * (b-1) / 2;

            if(p == k){
                cout << a + b << endl;
                rep(i, a){
                    cout << "0 ";
                }
                rep(i, b-1){
                    cout << "1 ";
                }
                cout << 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
