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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

inline int extMOD(int a, int m){
    return (a % m + m) % m;
}

tuple<int, int, int> extGCD(int a, int b){
    if(b == 0){
        return make_tuple(a, 1, 0);
    }

    // b * xx + (a % b) * yy = g
    tuple<int, int, int> res = extGCD(b, a % b);
    int g = get<0>(res);
    int xx = get<1>(res);
    int yy = get<2>(res);

    // a = (a / b) * b + (a % b)
    // a * x + b * y = g
    // ((a / b) * b + (a % b)) * x + b * y = g
    // b * ((a / b) * x + y) + (a % b) * x = g
    // xx = (a / b) * x + y
    // yy = x
    int x = yy;
    int y = xx - (a / b) * x;
    return make_tuple(g, x, y);
}

pair<int, int> CRT(const vector<int>& b, const vector<int>& m){
    int r = 0;
    int M = 1;

    rep(i, SZ(b)){
        //r * p + m[i] * q = d
        tuple<int, int, int> euc = extGCD(M, m[i]);
        int d = get<0>(euc);
        int p = get<1>(euc);

        if((b[i] - r) % d != 0){
            return make_pair(0, -1);
        }
        int nxtM = M * m[i] / d;
        int tmp = M * ((b[i] - r) / d) % nxtM * p % nxtM;
        M = nxtM;
        r = extMOD(r + tmp, M);
    }
    return make_pair(r, M);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 30;
    vector<int> a(n);
    vector<int> b(20), m(20);
    for(int i = 1; i <= 20; i++){
        cin >> a[i];
        b[i-1] = a[i] % i;
        m[i-1] = i;
    }
    for(int i = 21; i < 30; i++){
        cin >> a[i];
    }
    P p = CRT(b, m);

    if(p.second == -1 || p.first > 1e12){
        cout << "invalid" << endl;
        return 0;
    }

    for(int x = p.first; x <= 1e12; x += p.second){
        bool ok = true;
        for(int i = 1; i < 30; i++){
            int cnt = 0;
            int y = x;
            while(y != 0){
                cnt += y % (i + 1);
                y /= (i + 1);
            }
            if(cnt != a[i]){
                ok = false;
            }
        }
        if(ok){
            cout << x << endl;
            return 0;
        }
    }

    cout << "invalid" << endl;

    return 0;
}
