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
    int a, b, n;
    string x;
    cin >> a >> b >> n >> x;

    for(char c : x){
        if(c == 'S'){
            if(a > 0){
                a--;
            }
        }else if(c == 'C'){
            if(b > 0){
                b--;
            }
        }else{
            if(a >= b){
                if(a > 0){
                    a--;
                }
            }else{
                if(b > 0){
                    b--;
                }
            }
        }
    }
    cout << a << endl;
    cout << b << endl;

    return 0;
}
