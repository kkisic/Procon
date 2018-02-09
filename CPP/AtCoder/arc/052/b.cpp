#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int n, q;
    cin >> n >> q;

    vector<double> x(n), r(n), h(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> r[i] >> h[i];
    }
    vector<int> a(q), b(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i];
    }

    vector<double> v(2e4+1);
    for(int i = 1; i <= 2e4; i++){
        for(int j = 0; j < n; j++){
            if(i <= x[j]){
                continue;
            }

            v[i] += r[j]*r[j]*M_PI*h[j]/3;
            if(x[j] < i && i <= x[j] + h[j]){
                double rr = (x[j] + h[j] - (double)i) * r[j] / h[j];
                v[i] -= rr*rr*M_PI*(x[j]+h[j]-(double)i)/3;
            }
        }
    }

    for(int i = 0; i < q; i++){
        cout << fixed << setprecision(10) << v[b[i]] - v[a[i]] << endl;
    }

    return 0;
}
