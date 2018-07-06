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

const int BIAS = 20;

signed main(){
    while(true){
        double r;
        int n;
        cin >> r >> n;

        if(r == 0 && n == 0){
            break;
        }

        vector<double> bill(20*2);
        rep(i, n){
            double xl, xr, h;
            cin >> xl >> xr >> h;
            for(int j = xl; j < xr; j++){
                bill[j+BIAS] = max(bill[j+BIAS], h);
            }
        }

        double min = 100.0;
        for(int i = -r; i < 0; i++){
            double d = i+1;
            double len = bill[i+BIAS] - sqrt(r*r - d*d) + r;

            if(min > len){
                min = len;
            }
        }

        for(int i = 0; i < r; i++){
            double d = i;
            double len = bill[i+BIAS] - sqrt(r*r - d*d) + r;

            if(min > len){
                min = len;
            }
        }
        cout << fixed << setprecision(4) << min << endl;
    }

    return 0;
}
