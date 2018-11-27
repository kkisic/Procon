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

void f(int n){
    switch(n){
        case 0:
            cout << "Sun" << endl;
            break;
        case 1:
            cout << "Mon" << endl;
            break;
        case 2:
            cout << "Tue" << endl;
            break;
        case 3:
            cout << "Wed" << endl;
            break;
        case 4:
            cout << "Thu" << endl;
            break;
        case 5:
            cout << "Fri" << endl;
            break;
        case 6:
            cout << "Sat" << endl;
            break;
        default:
            break;
    }
}

int g(string s){
    if(s == "Sun"){
        return 0;
    }
    if(s == "Mon"){
        return 1;
    }
    if(s == "Tue"){
        return 2;
    }
    if(s == "Wed"){
        return 3;
    }
    if(s == "Thu"){
        return 4;
    }
    if(s == "Fri"){
        return 5;
    }
    if(s == "Sat"){
        return 6;
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        f((g(s) + 1) % 7);
    }

    return 0;
}
