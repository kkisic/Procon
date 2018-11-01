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

int u = 1;
int f = 2;
int r = 3;
int l = 4;
int b = 5;
int d = 6;

void turn(int& x, int& y, int& z, int& w){
    int tmp = x;
    x = y;
    y = z;
    z = w;
    w = tmp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 1;
    rep(i, n){
        string s;
        cin >> s;

        if(s == "North"){
            turn(u, f, d, b);
        }
        if(s == "East"){
            turn(u, l, d, r);
        }
        if(s == "West"){
            turn(u, r, d, l);
        }
        if(s == "South"){
            turn(u, b, d, f);
        }
        if(s == "Right"){
            turn(f, r, b, l);
        }
        if(s == "Left"){
            turn(f, l, b, r);
        }
        ans += u;
    }
    cout << ans << endl;

    return 0;
}
