#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;
const double eps = 1e-8;

signed main(){
    double p, m;
    cin >> p;

    double l = 0;
    double r = p;

    for(int i = 0; i < 100; i++){
        m = (l + r) / 2;

        double a = m + p / pow(2.0, m / 1.5);
        double b = (m + eps) + p / pow(2.0, (m + eps) / 1.5);

        if(a > b){
            l = m;
        }else{
            r = m;
        }
    }

    double ans = m + p / pow(2.0, m / 1.5);

    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}
